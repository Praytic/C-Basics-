#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include "time.h"
#include <queue>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

vector<vector<int>> g;
int n, m;
int sta, fin;

int main() {
	cin >> n >> m;
	g = vector<vector<int>>(n);
	int x, y;
	forn(i, m) {
		cin >> x >> y;
		g[x-1].push_back(y-1);
		g[y-1].push_back(x-1);
	}
		
	int pts = 0;
	vector<int> points;
	forn(irl, n) {
		int currentPoints = 0;
		queue<int> q;
		vector<bool> used (n);
		vector<int> d (n), p (n);
		q.push ((irl != 0) ? 0 : 1);
		used[(irl != 0) ? 0 : 1] = true;
		used[irl] = true;
		p[(irl != 0) ? 0 : 1] = -1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i=0; i<g[v].size(); ++i) {
				int to = g[v][i];
				if (!used[to]) {
					currentPoints++;
					used[to] = true;
					q.push(to);
					d[to] = d[v] + 1;
					p[to] = v;
				}
			}
		}
		if (currentPoints < n-2) {
			pts++;
			points.push_back(irl);
		}
	}

	cout << pts << endl;
	forn(i, points.size()) cout << points[i]+1 << ' ';
	cout << endl;
}
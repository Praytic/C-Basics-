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
		
	int cnt = 1;
	queue<int> q;
	vector<int> used (n, 0);
	vector<int> d (n), p (n);
	forn(irl, n) if (used[irl] == 0) {
		q.push (irl);
		used[irl] = cnt;
		p[irl] = -1;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int i=0; i<g[v].size(); ++i) {
				int to = g[v][i];
				if (!used[to]) {
					used[to] = cnt;
					q.push(to);
					d[to] = d[v] + 1;
					p[to] = v;
				}
			}
		}
		cnt++;
	}

	cout << cnt-1 << endl;
	forn(i, n) cout << used[i] << ' ';
	cout << endl;
}
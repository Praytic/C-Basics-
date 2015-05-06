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

int dx[8]={0,0,1,-1,-1,1,1,-1};
int dy[8]={1,-1,0,0,-1,-1,1,1};
string pathsX[3] = {"W", "", "E"};
string pathsY[3] = {"N", "", "S"};

const int INF = 1000000000;
const int N = 100000;
//vector<int> d(N, INF);
//vector<bool> used(N, false);
vector<vector<int>> g;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	g = vector<vector<int>>(n, vector<int>(3, -1));
	forn(i, n) {
		forn(j, 3) {
			ll ii = 1;
			forn(k, j + 1)
				ii *= i;
			ii = (ii + 1) % n;
			if (ii != g[i][0] && ii != g[i][1] && ii != g[i][2])
				g[i][j] = ii;
			else 
				g[i].pop_back();
		}
	}

	queue<int> q;
	vector<bool> used (n);
	vector<int> d (n), p (n);
	q.push (a);
	used[a] = true;
	p[a] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}

	if (!used[b])
		cout << -1;
	else {
		vector<int> path;
		for (int v = b; v != -1; v = p[v])
			path.push_back (v);
		reverse (path.begin(), path.end());
		cout << d[b] << endl;
		for (int i=0; i<path.size(); ++i)
			printf("%d ", path[i]);
	}
	return 0;
}
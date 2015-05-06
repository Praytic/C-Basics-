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

vector < vector<int> > g;
vector < vector<int> > matrixs;
int n;
int sta, fin;

int main() {
	cin >> n >> sta >> fin;
	sta--; fin--;
	matrixs = vector<vector<int>>(n, vector<int>(n));
	g = vector<vector<int>>(n);
	forn(i, n) forn(j, n) cin >> matrixs[i][j];
	forn(i, n) forn(j, n) {
		if (matrixs[i][j] == 1) g[i].push_back(j);
	}

	queue<int> q;
	q.push (sta);
	vector<bool> used (n);
	vector<int> d (n), p (n);
	used[sta] = true;
	p[sta] = -1;
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

	if (!used[fin])
		cout << -1;
	else {
		vector<int> path;
		for (int v = fin; v != -1; v = p[v])
			path.push_back (v);
		reverse (path.begin(), path.end());
		cout << d[fin] << endl;
		for (int i=0; i<path.size(); ++i)
			cout << path[i] + 1 << ' ';
	}
}
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
vector<vector<pair<int, int>>> g;
int n, m;
pair<int, int> s, f;

pair<int, int> operator +(const pair<int, int> &a, const pair<int, int> &b) { 
	return make_pair(a.first + b.first, a.second + b.second); 
}
pair<int, int> operator -(const pair<int, int> &a, const pair<int, int> &b) { 
	return make_pair(a.first - b.first, a.second - b.second); 
}
pair<int, int> operator *(const pair<int, int> &a, const pair<int, int> &b) { 
	return make_pair(a.first * b.first, a.second * b.second); 
}

int main() {
	cin >> n >> m;
	g = vector<vector<pair<int, int>>>(n*m);
	vector<string> h(n);
	forn(i, n) cin >> h[i];
	forn(i, n) forn(j, m) {
		if (h[i][j] != '#') {
			forn(k, 8) {
				if (dx[k]+i < n && dy[k]+j < m && dx[k]+i >= 0 && dy[k]+j >= 0) if (h[i+dx[k]][j+dy[k]] != '#') {
					g[i*m+j].push_back(make_pair(i+dx[k], j+dy[k]));
				}
			}
		}
		if (h[i][j] == 'S') {
			s = make_pair(i, j);
		}
		if (h[i][j] == 'F') {
			f = make_pair(i, j);
		}
	}

	queue<pair<int, int>> q;
	q.push (s);
	vector<vector<bool>> used (n, vector<bool> (m));
	vector<vector<int>> d (n, vector<int> (m));
	vector<vector<pair<int, int>>> p (n, vector<pair<int, int>> (m));
	used[s.first][s.second] = true;
	p[s.first][s.second] = make_pair(-1,-1);
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < g[v.first*m+v.second].size(); ++i) {
			pair<int, int> to = g[v.first*m+v.second][i];
			if (!used[to.first][to.second]) {
				used[to.first][to.second] = true;
				q.push(to);
				d[to.first][to.second] = d[v.first][v.second] + 1;
				p[to.first][to.second] = v;
			}
		}
	}

	if (!used[f.first][f.second])
		cout << -1;
	else {
		vector<pair<int, int>> path;
		for (pair<int, int> v = f; v != make_pair(-1,-1); v = p[v.first][v.second])
			path.push_back (v);
		reverse (path.begin(), path.end());
		cout << d[f.first][f.second] << endl;
		for (int i=1; i<path.size(); ++i) {
			pair<int, int> newWay = path[i] - path[i-1];
			cout << pathsY[newWay.first+1] <<  pathsX[newWay.second+1]<< endl;
		}
	}
	return 0;
}
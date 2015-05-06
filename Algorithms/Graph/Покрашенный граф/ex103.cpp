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
const int N = 200;
vector<vector<pair<int, int>>> g(N);

int main() {
	int n, m;
	cin >> n >> m;
	forn(i, m) {
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		x--, y--, c--;
		g[x].push_back(make_pair(y,c));
	}

	queue<pair<int, int>> q;
	vector<vector<bool>> used (n+1, vector<bool>(3));
	vector<vector<int>> d (n+1, vector<int>(3, INF));
	vector<vector<pair<int, int>>> p (n+1, vector<pair<int,int>>(3));
	q.push (make_pair(0, 0));
	used[0][0] = true;
	used[0][1] = true;
	used[0][2] = true;
	d[0][0] = 0;
	d[0][1] = 0;
	d[0][2] = 0;
	p[0][0] = make_pair(-1,-1);
	p[0][1] = make_pair(-1,-1);
	p[0][2] = make_pair(-1,-1);
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < g[v.first].size(); ++i) {
			pair<int, int> to = g[v.first][i];
			if (!used[to.first][to.second] && (to.second != v.second || p[v.first][0].first == -1)) {
				used[to.first][to.second] = true;
				q.push(to);
				d[to.first][to.second] = d[v.first][v.second] + 1;
				p[to.first][to.second] = v;
			}
		}
	}

	if (!used[n-1][0] && !used[n-1][1] && !used[n-1][2])
		cout << -1 << endl;
	else
		cout << min(min(d[n-1][0],d[n-1][1]),d[n-1][2]) << endl;
	return 0;
}
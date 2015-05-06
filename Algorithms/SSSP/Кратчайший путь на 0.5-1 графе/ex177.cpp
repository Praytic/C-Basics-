#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
typedef long long ll;

const int INF = 1000000000;

int main() {
	int n,m;
	int start, finish;
	cin >> n >> m >> start >> finish;
	start--;
	finish--;
	vector<vector<pair<int,int>>> g(n);
	int v1,v2,p,l;
	forn(i, m) {
		int bl;
		cin >> v1 >> v2 >> bl;
		(bl == 1) ? p = 1 : p = 2;
		v1--;
		v2--;
		g[v1].push_back(make_pair(v2,p));
		g[v2].push_back(make_pair(v1,p));
	}

	queue<pair<int, int>> q;
	vector<int> d (n, INF);
	q.push (make_pair(start, 0));
	d[start] = 0;
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		vector<bool> used (n);
		for (int i = 0; i < g[v.first].size(); ++i) {
			pair<int, int> to = g[v.first][i];
			if (d[v.first] + to.second < d[to.first]) {
				q.push(to);
				d[to.first] = d[v.first] + to.second;
			}
		}
	}
	if(d[finish] == INF) cout << "No solution" << endl;
	else cout << (double)d[finish]/2 << endl;
	
	return 0;
}
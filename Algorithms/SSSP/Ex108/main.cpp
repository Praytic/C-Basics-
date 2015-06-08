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
#define ini(type, n) \
		type n; \
		cin >> n;
#define s(n) n.size()

int INF = 1e9;
vector<vector<pair<int, int>>> g;

int main() {
	int n, m;
	int start, finish;
	cin >> n >> m >> start >> finish;
	finish--, start--;
	g = vector<vector<pair<int, int>>>(n);
	int a, b, c;
	forn(i, m) {
		cin >> a >> b >> c;
		g[a-1].push_back(make_pair(b-1, c));
		g[b-1].push_back(make_pair(a-1, c));
	}
		
	queue<pair<int, int>> q;
	vector<int> d (n, INF);
	vector<pair<int, int>> p (n);
	q.push (make_pair(start, 0));
	d[start] = 0;
	p[start] = make_pair(-1, -1);
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		vector<bool> used (n);
		for (int i = 0; i < g[v.first].size(); ++i) {
			pair<int, int> to = g[v.first][i];
			if (d[v.first] + to.second < d[to.first]) {
				q.push(to);
				d[to.first] = d[v.first] + to.second;
				p[to.first] = v;
			}
		}
	}
	

	if (d[finish] == INF)
		cout << -1;
	else
		cout << d[finish] << endl;
	return 0;
}
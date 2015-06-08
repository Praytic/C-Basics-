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
	cin >> n >> m;
	vector<vector<pair<int,int>>> g(n);
	int v1,v2,p,l;
	forn(i,m)
	{
		cin >> l;
		if(l == 1)
		{
			cin >> v1 >> v2 >> p;
			v1--;
			v2--;
			g[v1].push_back(make_pair(v2,p));
		}
		else
		{
			int start, finish;
			cin >> start >> finish;
			start--;
			finish--;
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
			if(d[finish]==INF) cout << -1 << endl;
			else cout << d[finish] << endl;
		}
	}
	return 0;
}
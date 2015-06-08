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

int n, m, v;
vector<vector<int>> e;
const int INF = 1000000000;

int main() {
	cin >> n >> m;
	e = vector<vector<int>>(m, vector<int> (3));
	forn(i, m) {
		cin >> e[i][0] >> e[i][1] >> e[i][2];
		e[i][0]--, e[i][1]--;
	}
	vector<int> d (n, INF);
	d[v] = 0;
	while (true) {
		bool f = false;
		for (int j=0; j<m; ++j)
			if (d[e[j][0]] < INF)
				if (d[e[j][1]] > d[e[j][0]] + e[j][2]) {
					d[e[j][1]] = d[e[j][0]] + e[j][2];
					f = true;
				}
		if (!f)  break;
	}
	
	for (int i = 1; i < n; i++) {
		if (d[i] == INF) cout << "NO";
		else cout << d[i];
		cout << endl;
	}
}
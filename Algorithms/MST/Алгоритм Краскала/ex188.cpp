#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <memory>

using namespace std;

#define forn(i, n) for(size_t i = 0; i < n; i++)
#define all(n) (n).begin() (n).end()
typedef long long ll;

vector<ll> p;
vector < pair < int, pair<int,int> > > g;
int n, m;

int dsu_get (int v) {
	return (v == p[v]) ? v : (p[v] = dsu_get (p[v]));
}

void dsu_unite (int a, int b) {
	a = dsu_get (a);
	b = dsu_get (b);
	if (rand() & 1)
		swap (a, b);
	if (a != b)
		p[a] = b;
}

bool cmp(vector<ll> a, vector<ll> b) {
	return a[2] < b[2];
}

int main() {
	cin >> n >> m;
	g = vector < pair < int, pair<int,int> > >(m);
	forn(i, m) {
		cin >> g[i].second.first >> g[i].second.second >> g[i].first;
		g[i].second.first--, g[i].second.second--;
	}
	ll cost = 0;
	vector < pair<ll, ll> > res;

	sort (g.begin(), g.end());
	p.resize (n);
	for (int i=0; i<n; ++i)
		p[i] = i;
	for (int i=0; i<m; ++i) {
		int a = g[i].second.first,  b = g[i].second.second,  l = g[i].first;
		if (dsu_get(a) != dsu_get(b)) {
			cost += l;
			res.push_back (g[i].second);
			dsu_unite (a, b);
		}
	}
	cout << cost << endl;
	forn(i, res.size()) cout << res[i].first+1 << ' ' << res[i].second+1 << endl;
	return 0;
}
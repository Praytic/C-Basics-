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
#define all(a) a.begin(),a.end()
 
int INF = 1e9;
 
int main() {
	int n,m ;
	cin >> n >> m;
	vector < vector<int> > g(n, vector<int>(n));
	forn(i,n)
		forn(j,n)
			g[i][j]=INF;
	ll ans=0;
	forn(i,m){
		int v1,v2,p;
		scanf("%d %d %d",&v1,&v2,&p);
		g[v1-1][v2-1]=min(g[v1-1][v2-1],p);
		g[v2-1][v1-1]=min(g[v2-1][v1-1],p);
	}
	vector<bool> used (n);
	vector<int> min_e (n, INF), sel_e (n, -1);
	vector<pair<int,int>> answer;
	min_e[0] = 0;
	for (int i=0; i<n; ++i) {
		int v = -1;
		for (int j=0; j<n; ++j)
			if (!used[j] && (v == -1 || min_e[j] < min_e[v]))
				v = j;
 
		used[v] = true;
		if (sel_e[v] != -1)
		{
			ans+=g[v][sel_e[v]];
			answer.push_back(make_pair(v, sel_e[v]));
		}
		for (int to=0; to<n; ++to)
			if (g[v][to] < min_e[to]) {
				min_e[to] = g[v][to];
				sel_e[to] = v;
			}
	}
	cout << ans << endl;
	for (int i=0; i<(int)answer.size(); ++i) {
		printf("%d %d \n",answer[i].first + 1, answer[i].second + 1);
	}
	return 0;
}
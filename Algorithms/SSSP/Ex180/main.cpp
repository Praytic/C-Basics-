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

ll INF = (ll)1e12;
vector<vector<pair<int, ll> > > g;

int main() {
    int n, m;
    int start, finish;
    cin >> n >> m;
    g = vector<vector<pair<int, ll> > >(n);
    int a, b;
    ll c;
    forn(i, m) {
            cin >> a >> b >> c;
            g[a-1].push_back(make_pair(b-1, c));
            g[b-1].push_back(make_pair(a-1, c));
    }
        start=0;
    finish=n-1;
    vector<ll> d (n, INF);
    vector< int > p (n);
    d[start] = 0;
    p[start] = -1;

    set < pair<int,int> > q;
    int s = start;
    q.insert (make_pair (d[s], s));
    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase (q.begin());

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to]) {
                q.erase (make_pair (d[to], to));
                d[to] = d[v] + len;
                p[to] = v;
                q.insert (make_pair (d[to], to));
            }
        }
    }


    if (d[finish] == INF)
        {
                cout << "No solution" << endl;
                return 0;
        }
        vector<int> ans;
        ans.push_back(finish);
        while(p[finish] != -1)
        {
                ans.push_back(p[finish]);
                finish=p[finish];
        }
        reverse(all(ans));
        forn(i,(int)ans.size())
                cout << ans[i]+1 << " ";
    return 0;
}
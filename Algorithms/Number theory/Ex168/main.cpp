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

#define forn(i,n) for(ll i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
	if (a.second != b.second)
		return a.second > b.second;
	else
		return a.first < b.first;
}

int main() {

	ll n;
	cin >> n;
	vector<pair<ll, ll>> a;
	ll nn = n;
	for(ll i = 2; i*i <= nn; i++) {
		if (n%i==0) {
			ll cnt = 0;
			while (n%i == 0) {
				cnt++;
				n/=i;
			}
			a.push_back(make_pair(i, cnt));
		}
	}
	if (n!=1) a.push_back(make_pair(n, 1));
	sort(a.begin(), a.end(), cmp);
	
	cout << a.size() << endl;
	forn(i, a.size()) cout << a[i].first << ' '<< a[i].second << ' ';
	return 0;
}
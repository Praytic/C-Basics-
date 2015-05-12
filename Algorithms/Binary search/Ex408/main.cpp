#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

int main() {
	ini(int, n);
	ini(ll, k);
	vector<pair<ll, ll>> vec1(n);
	ll l = 2 * 10e9;
	ll r = -2 * 10e9;
	forn(i, n) {
		cin >> vec1[i].first >> vec1[i].second;
		r = max(r, vec1[i].second);
		l = min(l, vec1[i].first);
	}

	r++; l--;
	ll sumLength = 0;
	ll mid;
	while (r - l > 1) {
		sumLength = 0;
		mid = (l + r) / 2;
		forn(i, n) {
			if (min(vec1[i].second, mid) - vec1[i].first < 0) continue;
			sumLength += min(vec1[i].second, mid) - vec1[i].first+1;
		}
		if (sumLength > k)
			r = mid;
		else
			l = mid;
	}
	sumLength = 0;
	for (ll j = l; j <= r; j++) {
		forn(i, n) {
			if (min(vec1[i].second, j) - vec1[i].first + 1< 0) continue;
			sumLength += min(vec1[i].second, j) - vec1[i].first + 1;
		}
		if (sumLength > k) {
			cout << j << endl;
			return 0;
		}
		sumLength = 0;
	}
}

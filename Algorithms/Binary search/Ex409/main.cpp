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
#include "math.h"

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

ll f(int k, int n, ll mid, vector<ll> vec1) {
	ll sum = 0;
	forn(i, vec1.size()) {
		if (vec1[i] > mid)
			sum += mid;
		else
			sum += vec1[i];
	}
	return sum / mid;
}

int main()
{
	ini(int, k);
	ini(int, n);
	vector <ll> vec1(n);
	forn(i, n) cin >> vec1[i];
	sort(vec1.begin(), vec1.end());
	reverse(vec1.begin(), vec1.end());

	ll r = n*1e9;
	ll l = 0;
	ll mid;
	while (r - l > 1) {
		mid = (r + l) / 2;
		if (f(k, n, mid, vec1) < k)
			r = mid;
		else
			l = mid;
	}
	for (ll i = l; i <= r; i++) {
		if (f(k, n, i, vec1) == k) {
			cout << i << endl;
			return 0;
		}
	}
}

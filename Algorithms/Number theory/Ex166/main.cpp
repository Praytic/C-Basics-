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

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

ll NOD(ll a, ll b) {
	return (a==0) ? b : NOD(b%a,a);
}

ll NOK(vector<ll> a) {
	ll nod = a[0];
	ll nok = a[0];
	for (int i = 1; i < a.size(); i++) {
		nod = NOD(nok, a[i]);
		nok *= a[i] / nod;
	}
	return nok;
}

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	forn(i, n) {
		cin >> a[i];
		a[i]++;
	}
	cout << NOK(a)-1 << endl;
}
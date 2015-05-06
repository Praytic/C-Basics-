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
	ini(int, m);
	vector<int> vecn(n);
	vector<int> result;
	forn(i, n) cin >> vecn[i];
	sort(vecn.begin(), vecn.end());
	vecn.erase(unique(vecn.begin(), vecn.end()), vecn.end());

	int vecm;
	int r = vecn.size();
	int l = 1;
	int mid;
	int counter = 0;
	forn(i, m) {
		cin >> vecm;
		if (vecm < vecn[l - 1] || vecm > vecn[r-1]) continue;
		while (r - l > 1) {
			mid = (l + r) / 2;
			if (vecn[mid-1] >= vecm)
				r = mid;
			else
				l = mid;
		}
		for (int j = l; j <= r; j++)
			if (vecm == vecn[j-1]) {
				result.push_back(vecm);
			}
		r = vecn.size();
		l = 1;
	}

	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	cout << result.size() << endl;
	forn(i, result.size()) cout << result[i] << ' ';
}
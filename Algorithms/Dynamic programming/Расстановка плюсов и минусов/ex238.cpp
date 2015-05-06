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

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

bool mas[100][20000];
int main()
{
	ini(int, n);
	ini(int, k);
	vector<int> vec(n);
	forn(i, n) cin >> vec[i];

	mas[0][10000 - vec[0]] = true;
	mas[0][10000 + vec[0]] = true;
	for (int i = 1; i < n; i++) {
		forn(j, 20000) {
			if (mas[i-1][j]) {
				mas[i][j - vec[i]] = true;
				mas[i][j + vec[i]] = true;
			}
		}
	}
	if (mas[n - 1][10000 + k]) cout << "YES" << endl;
	else cout << "NO" << endl;
}
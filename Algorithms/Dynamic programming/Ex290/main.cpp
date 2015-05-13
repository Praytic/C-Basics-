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

int main() {
	ini(int, n);
	ini(int, m);
	vector<int> stonesTaken(n+1);
	int minStonesTaken = INT_MAX;
	int maxStonesTaken = INT_MIN;
	for (int i = 1; i <= n; i++) {
		cin >> stonesTaken[i];
		minStonesTaken = min(minStonesTaken, stonesTaken[i]);
		maxStonesTaken = max(maxStonesTaken, stonesTaken[i]);
	}
	vector<int> waysToWin(m+21, 2);
	for (int i = 0; i <= m; i++) {
		if (waysToWin[i] == 2) {
			for (int j = 1; j <= n; j++) {
				waysToWin[i + stonesTaken[j]] = 1;
			}
		}
	}
	/*for (int i = m; i >= 0; i--) {
		cout << i << ": " << waystowin[i] << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		if (waysToWin[m - stonesTaken[i]] == 2) {
			cout << "FIRST" << endl << i << endl;
			return 0;
		}
	}
	cout << "SECOND" << endl;
}
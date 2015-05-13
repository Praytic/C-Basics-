#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

bool mas[100][20000];
int main()
{
	ini(int, n);
	vector<int> vec(n);
	forn(i, n) cin >> vec[i];

	mas[0][10000] = true;
	for (int i = 1; i <= n; i++) {
		forn(j, 20000) {
			if (mas[i - 1][j]) {
				mas[i][j - vec[i-1]] = true;
				mas[i][j + vec[i-1]] = true;
			}
		}
	}

	int j;
	for (int i = 10000; i < 20000; i++) {
		if (mas[n][i]) {
			j = i;
			break;
		}
		if (mas[n][20000 - i]) {
			j = 20000-i;
			break;
		}
	}

	vector<int> group1;
	vector<int> group2;
	for (int i = n; i >= 1; i--) {
		if (mas[i-1][j + vec[i - 1]]) {
			j += vec[i-1];
			group1.push_back(i);
		}
		else {
			j -= vec[i-1];
			group2.push_back(i);
		}
	}

	cout << group2.size() << ' ';
	for (int i = group2.size() - 1; i >= 0; i--) cout << group2[i] << ' ';
}
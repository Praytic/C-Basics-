#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

int k, n, l;
vector<vector<int>> used;
ll cnt;
int horse;
bool pos = false;
int i, j;

void rec(int l) {
	if (horse == k) {
		/*for (int i1 = 0; i1 < n; i1++) {
		for (int j1 = 0; j1 < n; j1++)
			if (used[i1][j1] == 2) cout << '*';
			else cout << '.';
			cout << endl;
		}
		cout << endl;*/
		cnt++;
		//if (cnt == 10000) cin >> i;
		return;
	}
	for(; l < n*n && horse < k; l++) {
		i = l/n;
		j = l%n;
		if (used[i][j] == 0) {
			if (j+1 >= 0 && i+2 >= 0 && j+1 < n && i+2 < n) used[i+2][j+1]++;
			if (j-1 >= 0 && i+2 >= 0 && j-1 < n && i+2 < n) used[i+2][j-1]++;
			if (j+1 >= 0 && i-2 >= 0 && j+1 < n && i-2 < n) used[i-2][j+1]++;
			if (j-1 >= 0 && i-2 >= 0 && j-1 < n && i-2 < n) used[i-2][j-1]++;
			if (j+2 >= 0 && i+1 >= 0 && j+2 < n && i+1 < n) used[i+1][j+2]++;
			if (j-2 >= 0 && i+1 >= 0 && j-2 < n && i+1 < n) used[i+1][j-2]++;
			if (j+2 >= 0 && i-1 >= 0 && j+2 < n && i-1 < n) used[i-1][j+2]++;
			if (j-2 >= 0 && i-1 >= 0 && j-2 < n && i-1 < n) used[i-1][j-2]++;
			used[i][j] = INT_MAX;
			horse++;
			rec(l+1);
			i = l/n;
			j = l%n;
			horse--;
			used[i][j] = 0;
			if (j+1 >= 0 && i+2 >= 0 && j+1 < n && i+2 < n) used[i+2][j+1]--;
			if (j-1 >= 0 && i+2 >= 0 && j-1 < n && i+2 < n) used[i+2][j-1]--;
			if (j+1 >= 0 && i-2 >= 0 && j+1 < n && i-2 < n) used[i-2][j+1]--;
			if (j-1 >= 0 && i-2 >= 0 && j-1 < n && i-2 < n) used[i-2][j-1]--;
			if (j+2 >= 0 && i+1 >= 0 && j+2 < n && i+1 < n) used[i+1][j+2]--;
			if (j-2 >= 0 && i+1 >= 0 && j-2 < n && i+1 < n) used[i+1][j-2]--;
			if (j+2 >= 0 && i-1 >= 0 && j+2 < n && i-1 < n) used[i-1][j+2]--;
			if (j-2 >= 0 && i-1 >= 0 && j-2 < n && i-1 < n) used[i-1][j-2]--;
		}
	}
}

int main()
{
	cin >> n >> k;
	used = vector<vector<int>>(n, vector<int>(n));
	rec(0);
	cout << cnt << endl;
}
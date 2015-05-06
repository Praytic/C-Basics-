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

int main()
{
	ini(int, n);
	vector<vector<int>> vec(n, vector<int>(n+1));
	vector<vector<int>> sumvec(n, vector<int>(n));
	forn(i, n)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> vec[i][j+1];
			vec[i][j + 1] += 100;
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= i+1; j++)
		{
			vec[i][j] = max(vec[i - 1][j-1] + vec[i][j], vec[i - 1][j] + vec[i][j]);
		}
	}
	int result = -101;
	forn(i, n + 1)
	{
		result = max(result, vec[n-1][i]-100*n);
	}
	cout << result << endl;
}
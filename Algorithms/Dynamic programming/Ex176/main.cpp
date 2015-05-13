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
	ini(int, m);
	string cini;
	vector<vector<int>> vec(n+1, vector<int>(m+1));
	for (int i = 0; i < n; i++)
	{
		cin >> cini;
		for (int j = 0; j < m; j++)
		{
			if (cini[j] == '*')
				vec[i+1][j+1] = -1;
			else
				vec[i+1][j+1] = cini[j] - '0';
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (vec[i][j] != -1 && (vec[i - 1][j] + vec[i][j - 1] >= 0))
				vec[i][j] = max(vec[i][j] + vec[i - 1][j], vec[i][j] + vec[i][j - 1]);
			else if (vec[i - 1][j] + vec[i][j - 1] < 0)
				vec[i][j] = -1;
			else if (vec[i][j] == -1)
				vec[i][j] = -1;
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << vec[i][j] << ' ';
		}
		cout << endl;
	}*/

	if (vec[n][m] == -1)
		cout << "SEE YOU LATER\n";
	else
		cout << vec[n][m] << endl;

}
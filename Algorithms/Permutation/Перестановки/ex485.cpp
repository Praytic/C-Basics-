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


int main()
{
	ini(int, n);
	int cini;
	int count = 1;
	int maxj = 0;
	vector<vector<bool>> p(n);
	vector<int> result(n);
	vector<pair<int,int>> maxp(n);
	forn(i, n)
	{
		cin >> cini;
		bool check = false;
		int count2 = 1;
		forn(j, n)
		{
			if (cini - 1 >= p[j].size())
				p[j].insert(p[j].end(), cini-p[j].size(), false);
			if (!p[j][cini-1])
			{
				check = true;
				p[j][cini - 1] = true;
				result[i] = j;
				maxp[j].first++;
				maxp[j].second = max(maxp[j].second, cini);
				break;
			}
			count2++;
		}
		count = max(count2, count);
		if (!check)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	forn(i, count)
	{
		if (maxp[i].first != maxp[i].second)
		{
			cout << -1 << endl;
			return 0;
		}
	}
	cout << count << endl;
	forn(i, n)
	{
		cout << result[i]+1 << ' ';
	}
	cout << endl;
	return 0;
}
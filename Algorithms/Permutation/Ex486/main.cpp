#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

const ll POW = 35;

int main()
{
	ini(int, n);
	ini(ll, k);
	vector<vector<int>> Qgraf(POW, vector<int>(n));
	vector<vector<ll>> Qwght(POW, vector<ll>(n));
	vector<vector<ll>> Qwghtmin(POW, vector<ll>(n));

	forn(i, n)
		scanf("%d", &Qgraf[0][i]);
	forn(i, n)
		scanf("%lld", &Qwght[0][i]);

	Qwghtmin[0] = Qwght[0];

	for (int j = 1; j < POW; j++)
	{
		for (int i = 0; i < n; i++)
		{
			Qgraf[j][i] = Qgraf[j - 1][Qgraf[j - 1][i]];
			Qwght[j][i] = Qwght[j - 1][Qgraf[j - 1][i]] + Qwght[j - 1][i];
			Qwghtmin[j][i] = min(Qwghtmin[j-1][i], Qwghtmin[j - 1][Qgraf[j - 1][i]]);
		}
	}

	vector<ll>resCnt(n);
	vector<ll>resMin(n, LLONG_MAX);

	forn(i, n)
	{
		ll pow = k;
		int pos = i;
		int j = 35;
		while (pow != 0)
		{
			ll st = 1ll << j;
			if (pow - st >= 0)
			{
				resCnt[i] += Qwght[j][pos];
				resMin[i] = min(resMin[i], Qwghtmin[j][pos]);

				pos = Qgraf[j][pos];
				pow -= st;
			}
			j--;
		}
	}

	forn(i, n)
	{
		printf("%lld %lld\n", resCnt[i], resMin[i]);
	}
	return 0;
}
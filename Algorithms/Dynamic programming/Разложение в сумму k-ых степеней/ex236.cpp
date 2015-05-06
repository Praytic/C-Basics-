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
	ini(int, k);
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);

	if (k == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	int poweres = 0;
	for (int i = 2; poweres < n; i++)
	{
		poweres = 1;
		forn(j,k)
			poweres *= i;
		vec.push_back(poweres);
	}

	vector<int> z(n + 1);
	z[0] = 0;
	for (int i = 1; i < n+1; i++)
	{
		z[i] = 1e5;
		for (int j = 1, k = i - vec[1]; j < vec.size() && k >= 0; j++)
		{
			k = i - vec[j];
			if (k >= 0)
				z[i] = min(z[i], z[k] + 1);
		}
	}
	cout << z[n] << endl;
}
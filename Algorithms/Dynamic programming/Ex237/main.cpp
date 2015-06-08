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

using namespace std;

int main()
{
	ini(int, n);
	
	vector <int> a(n);
	vector <int> z(n);
	
	forn(i,n) cin >> a[i];

	forn(i, n)
	{
		z[i] = 1;
		forn(j, i)
		{
			if ((abs(a[i] % 2) != abs(a[j] % 2)) && (a[i] >= a[j]))
				z[i] = max(z[i], z[j] + 1);
		}
	}

	int res = 0;
	forn(i, n)
		res = max(res, z[i]);

	cout << res << endl;
}
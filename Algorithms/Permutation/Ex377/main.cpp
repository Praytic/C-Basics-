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

vector<int> cycles(vector<int> p, int n)
{
	bool sign = false;
	vector<int> wrong(1);
	wrong[0] = -1;
	vector<int> used(n);
	forn(i, n)
	{
		if (!used[i])
		{
			int j = i;
			int len = 0;
			while (!used[j])
			{
				used[j] = sign+1;
				sign = !sign;
				len++;
				j = p[j]-1;
			}
			if (len % 2 == 1)
				return wrong;
		}
	}
	return used;
}

int main()
{
	int a;
	ini(int, n);
	vector<int> p(n);
	vector<int> q(n);
	forn(i, n)
	{
		cin >> p[i];
	}
	q = cycles(p, n);
	forn(i, q.size())
	{
		cout << q[i] << ' ';
	}
	cout << endl;
	return 0;
}
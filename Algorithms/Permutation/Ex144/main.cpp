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

ll fact(ll n)
{
	if (n <= 1)
		return 1;
	else
		return n*fact(n - 1);
}

vector<int> kth_transpos(ll k, int n)
{
	vector<int> result;
	vector<bool> used(n);
	int n_const = n;
	int added;
	ll div = k;
	for (int i = n-1; i  >= 0; i--)
	{
		ll fact_value = fact(i);
		if (fact_value == 1)
		{
			if (k % 2 == 0)
			{
				for (int j = 0; j < n_const; j++)
				if (!used[j])
				{
					result.push_back(j + 1);
					used[j] = true;
				}
				return result;
			}
			else
			{
				for (int j = n_const - 1; j >= 0; j--)
				if(!used[j])
				{
					result.push_back(j + 1);
					used[j] = true;
				}
				return result;
			}
		}
		else
		{
			added = (int)(div / fact_value);
			div = (int)(div % fact_value);
		}
		int cycles_added = added;
		for (int j = 0; j < n_const; j++)
		{

			if (!used[j])
			{
				cycles_added--;
			}
			if (cycles_added == -1)
			{
				added = j;
				used[j] = true;
				break;
			}
		}
		result.push_back(added+1);
		used[added] = true;
	}
	return result;
}

int main()
{
	ini(int, n);
	ini(ll, k);
	vector<int> p(n);
	p = kth_transpos(k-1, n);
	forn(i, n)
	{
		cout << p[i] << ' ';
	}
	cout << endl;
	return 0;
}
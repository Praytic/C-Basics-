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

vector<int> trans_check(vector<int> p, int n, vector<int> special)
{
	vector<bool> used(n);
	forn(i, special.size())
	{
		used[special[i]] = true;
	}
	vector<int> result;
	result = p;
	int elements_before = 0;
	used[p[n-1]] = true;
	for (int i = n - 1; i > 0; i--)
	{
		used[p[i - 1]] = true;
		if (p[i - 1] > p[i] && n-i >= special.size())
		{
			for (int k = p[i-1]-1; k >= 0; k--)
			{
				if (used[k])
				{
					used[k] = false;
					result[i - 1] = k;
					break;
				}
			}
			int next = i;
			for (int k = n - 1; k >= 0; k--)
			{
				if (used[k])
				{
					used[k] = false;
					result[next] = k;
					next++;
				}
				if (next == n)
					return result;
			}
		}
		elements_before++;
	}
	return result;
}

vector<int> transposition(vector<int> p, int n)
{
	vector<bool> used(n);
	vector<int> result;
	vector<int> wrong(1);
	wrong[0] = -1;
	forn(i, n)
	{
		for (int j = min(p[i], n-1); j >= 0; j--)
		{
			if (!used[j])
			{
				used[j] = true;
				result.push_back(j);
				break;
			}
			if (j == 0)
			{
				result = p;
				break;
			}
		}
		if (result[i] < p[i] || result == p)
			break;
	}
	vector<int> special;
	for (int i = n - 1; i >= 0; i--)
	{
		if (!used[i])
		{
			result.push_back(i);
			used[i] = true;
		}
	}
	special.insert(special.begin(), result.begin() + n, result.end());
	result.erase(result.begin()+n, result.end());
	if (result == p)
		result = trans_check(p, n, special);
	if (result == p)
		return wrong;
	else
		return result;
}

int main() 
{
	ini(int, n);
	vector<int> p(n);
	vector<int> q(n);
	forn(i,n)
	{
		cin >> p[i];
	}
	q = transposition(p, n);
	forn(i, q.size())
	{
		cout << q[i] << ' ';
	}
	cout << endl;
	return 0;
}
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

vector<pair<int, string>> cycles(vector<int> p, int n)
{
	bool sign = false;
	vector<pair<int, string>> result;
	vector<bool> used(n);
	int len = 0;
	forn(i, n)
	{
		if (!used[i])
		{
			len++;
			int j = i;
			while (!used[j])
			{
				pair<int, string> add(j + 1, " -> ");
				result.push_back(add);
				used[j] = true;
				j = p[j]-1;
			}
			result[result.size() - 1].second = "\n";
		}
	}
	cout << len << endl;
	return result;
}

int main()
{
	int a;
	ini(int, n);
	vector<int> p(n);
	vector<pair<int, string>> q(n);
	forn(i, n)
	{
		cin >> p[i];
	}
	q = cycles(p, n);
	forn(i, q.size())
	{
		cout << q[i].first << q[i].second;
	}
	return 0;
}
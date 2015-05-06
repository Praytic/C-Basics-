#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long

int cycles_count(const vector<int> &p, int n)
{
	vector<bool> used(p.size()+1);
	int result = 0;
	int j;
	for (int i = 1; i <= n; i++)
	{
		if (!used[i])
		{
			int len = 0;
			j = i;
			while (!used[j])
			{
				len = 1;
				used[j] = true;
				j = p[j-1];
			}
			result += len;
		}
	}
	return result;
}



int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	vector<int> q(n);
	forn(i, n)
	{
		cin >> p[i];
	}
	cout << cycles_count(p, n) << endl;
	return 0;
}
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

bool transpos(vector<int> a)
{
	sort(a.begin(), a.end());
	forn(i, a.size())
	{
		if (a[i] != i+1)
			return false;
	}
	return true;
}


int main()
{
	int n, m;
	cin >> n;
	forn(i, n)
	{
		cin >> m;
		vector<int> a(m);
		forn(j,m)
		{
			cin >> a[j];
		}
		if (transpos(a))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
		
	return 0;
}
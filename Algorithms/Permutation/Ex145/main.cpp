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


ll transposition(const vector<int> p, const ll fact[])
{
	int size = p.size();
	ll trans = (p[0] - 1)*(fact[size - 1]) + 1;
	vector<bool> used(size);
	used[p[0]-1] = true;
	for (int i = 1; i < size; i++)
	{
		int diff = 0;
		used[p[i]-1] = true;
		for (int j = 0; j < p[i]; j++)
		{
			if (!used[j])
				diff++;
		}
		trans += diff*fact[size - (i + 1)];
	}
	return trans;
}

int main()
{
	ll fact[21]; 
	fact[0] = 1; 
	for (ll i = 1; i <= 20; i++) 
		fact[i] = fact[i - 1] * i;
	vector<int> p;
	int a;
	char nl = ' ';
	while (cin >> a) 
	{
		p.push_back(a);
		if (cin.peek() == '\n') break;
	}
	cout << p.size() << ' ' << transposition(p, fact) << endl;
	return 0;
}
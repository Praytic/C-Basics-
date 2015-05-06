#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

int calc (int n, double x) {
	if (n != 0) {
		return calc(n-1, x/(x+n));
	}
	else return x;
}

int main()
{
	ini(int, a);
	ini(double, b);
	cout << calc(a, b) << endl;
}

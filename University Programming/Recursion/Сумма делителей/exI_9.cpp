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

long long devSum (int c) {
	long long devCount;
	if (c == 0) 
		return 0;
	else
		devCount = !!(abs(c)-1)*(c/abs(c))+c;
	for (int i = 2; i <= c/2; i++) {
		if (c%i == 0) devCount+=i*(c/abs(c));
	}
	return devCount;
}

int main()
{
	ini(int, a);
	ini(int, b);
	for (int i = min(a, b); i <= max(a ,b); i++) {
		long long c = devSum(i);
		cout << i << ": ";
		if (c == 0) cout << "INF";
		else cout << c;
		cout << endl;
	}
}

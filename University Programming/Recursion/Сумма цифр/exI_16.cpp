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

int numSum (int c) {
	int sumCount = 0;
	while (c != 0) {
		sumCount += abs(c%10);
		c /= 10;
	}
	return sumCount;
}

int main()
{
	ini(int, a);
	if (a == 0) {
		cout << "ERROR\n";
		return 0;
	}
	int aSum = numSum(a);
	a--;
	while (aSum != numSum(a)) a--;
	cout << a << endl;
}

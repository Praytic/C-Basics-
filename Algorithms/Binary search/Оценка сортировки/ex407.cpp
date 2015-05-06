#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include "math.h"

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

int main() {
	ini(double, c);
	ini(double, t);
	double r = 2e9;
	double l = 1;
	double n, n1=-1;
	while (r - l > 1e-11) {
		n = (l + r) / 2;
		double mid = n*(log(n) / log(2.0));
		if (mid > t / c)
			r = n;
		else
			l = n;
		if (n1 == n) break;
		n1 = n;
	}
	printf("%.11f\n", n);
}
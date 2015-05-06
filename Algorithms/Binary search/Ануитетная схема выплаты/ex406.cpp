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

double f(double mid, double s, double m, double p) { 
	double a, b;
	forn(i, m) {
		a = s*p / 100;
		b = mid - a;
		s = s - b;
	}
	return s;
}

int main()
{
	ini(double, s);
	ini(double, m);
	ini(double, p);
	double r = 2*s;
	double l = 0;
	double mid, mid1 = -1;
	double result;
	while (r - l > 1e-6) {
		mid = (r + l) / 2;
		result = f(mid, s, m, p);
		if (result > 0)
			l = mid;
		else
			r = mid;
	}
	printf("%.5f\n", mid);
}
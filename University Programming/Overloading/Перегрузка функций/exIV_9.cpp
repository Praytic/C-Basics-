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

float F(float x) {
	return 1/((1+x)*(1+x));
}

void F(float x, float &y) {
	y = (x*x-1)*(x*x-1);
}

int main()
{
	ini(float, x);
	float y;
	if (x > 1) y=F(x);
	else if (x < 1) F(x, y);
	else y = 0;
	printf("%.5f\n", y);
}
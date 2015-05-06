#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>

using namespace std;
const double lu = 1e-8;
const double pi = 3.14159265359;
#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

bool equal(double a, double b){
	if (a > b && a - lu > b || a < b && a + lu < b)
		return false;
	else
		return true;
}

double func1(double i, double e, int &opCnt){
	double last = i;
	double result = i;
	for (int j = 1; abs(last) > e; j++){
		last *= (i * i * (j * 2 - 1)) / ((j * 2 + 1) * (j * 2));
		result += last;
		opCnt++;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "a: "; ini(double, a);
	cout << "b: "; ini(double, b);
	cout << "h: "; ini(double, h);
	cout << "e: "; ini(double, e);
	int j = 1;
	cout << setprecision(10) << setiosflags(ios::left) << setw(6) << "№№: " << setw(12) << "Значение x" << setw(24) << "Значение функции F(x)" << setw(4) << "n" << endl;
	for (double i = a; !equal(i, b+h); i += h, j++){
		int opCnt = 1;
		double func_res = func1(i, e, opCnt);
		cout << setw(2) << j << setw(4) << ": " << setw(12) << rint(i*1e8) / 1e8 << setw(24) << pi / 2 - rint(func_res*1e8) / 1e8 << setw(4) << opCnt << endl;
	}
}

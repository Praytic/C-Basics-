#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const double PO = 1e-12;

void f(double i)
{
	cout << setprecision(3) << fixed << i << ": ";
	if (PI / 2 - PO <= abs(i) && abs(i) <= PI + PO)
		cout << setprecision(15) << fixed << cos(i) << endl;
	else if (abs(i)>PI + PO)
		cout << 0 << endl;
	else if (abs(i) < PI / 2 - PO)
		cout << setprecision(15) << fixed << sin(i) << endl;
	else
		cout << "ERROR" << endl;
}

int main()
{
	double a, b, h;
	cout << "Enter range and step: ";
	cin >> a >> b >> h;
	for (double i = a; i <= b + PO; i += h)
	{
		f(i);
	}
}

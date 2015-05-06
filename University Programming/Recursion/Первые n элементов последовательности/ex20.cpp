#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159265359;
const double PO = 1e-12;

int main()
{
	int b1 = 1, b2 = 5;
	int n;
	cout << "Enter n: ";
	cin >> n;
	if (n >= 1)
	{
		cout << b1 << ' ';
		if (n >= 2)
			cout << b2 << ' ';
	}
	for (int i = 2; i<n; i++)
	{
		b1 = b2 - b1;
		cout << b1 << ' ';
		i++;
		if (i == n) break;
		b2 = b1 + b2;
		cout << b2 << ' ';
	}
}

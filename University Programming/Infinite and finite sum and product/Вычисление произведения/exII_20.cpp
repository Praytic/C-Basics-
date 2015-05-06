#include <iostream>

using namespace std;

int main()
{
	double x, op = 1;
	int k;
	cout << "Enter k and x: ";
	cin >> k >> x;
	double xp = x;
	for (int n = 0; n <= k; n++)
	{
xp = 1 + (pow(x, 2 * n)*pow(-1.0, n - 1)) / ((double)(n + 2)*(n + 1));
		op *= xp;
	}
	cout << "Op = " << op << endl;
}

// Убраны лишние заголовочные файлы и константы
#include <iostream>

using namespace std;

const double PI = 3.14159265359;
const double PO = 1e-12;

int main()
{
	double x, sum = 0;
	int n;
	cout << "Enter n and x: ";
	cin >> n >> x;
	for (int i = 0; i<n; i++)
	{
		x = sin(x);
		sum += x;
	}
	cout << "Sum = " << sum << endl;
}

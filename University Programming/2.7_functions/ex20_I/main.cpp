#include <iostream>
#include <cmath>

using namespace std;

// Объявление функции
double f(int x1, int y1, int x2, int y2) 
{
	return sqrt((x1 - x2)*(x1 - x2)*1.0 + (y1 - y2)*(y1 - y2)*1.0);
}

bool t(double a, double b, double c)
{
	if (a + b <= c || a + c <= b || b + c <= a)
		return false;
	else return true;
}

int main()
{
	int x1, x2, y1, y2, x3, y3, x4, y4, sum = 0;
	cout << "Type 1 coordinates: ";
	cin >> x1 >> y1;
	cout << "Type 2 coordinates: ";
	cin >> x2 >> y2;
	cout << "Type 3 coordinates: ";
	cin >> x3 >> y3;
	cout << "Type 4 coordinates: ";
	cin >> x4 >> y4;
// Вызов функций
	if (t(f(x1, y1, x2, y2), f(x1, y1, x3, y3), f(x2, y2, x3, y3))) 
	++sum;
	if (t(f(x1, y1, x3, y3), f(x1, y1, x4, y4), f(x4, y4, x3, y3)))
	++sum;
	if (t(f(x2, y2, x3, y3), f(x2, y2, x4, y4), f(x3, y3, x4, y4)))
	++sum;
	if (t(f(x4, y4, x1, y1), f(x4, y4, x2, y2), f(x2, y2, x1, y1)))
	++sum;
	cout << sum << endl;
}

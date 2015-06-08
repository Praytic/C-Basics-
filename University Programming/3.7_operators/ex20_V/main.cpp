#include <iostream>
// Этот заголовочный файл включает в себя функции форматирования вывода
#include <iomanip>
#include <cmath>

using namespace std;

// Объявление глобальной константы
const double PO = 1e-12;

// Передача параметра y по ссылке
void f(double x, double &y)
{
	if (abs(x)<1 - PO && abs(x)>-1 + PO)
	{
		y = 1 / (x + 7) + log(1 - abs(x));
// Выделение знаков после запятой
cout << setprecision(3) << fixed << x << ": " << setprecision(20) << fixed << y << endl;
	}
else 
cout << setprecision(3) << fixed << x << ": " << "NONE" << endl;
}

int main()
{
	double y;
	double a, b, h;
	cout << "Type a,b,h ([a,b]; h- step): ";
	cin >> a >> b >> h;
	for (double x = a; x <= b + PO; x += h)
	{
		f(x, y);
	}
	cout << endl;
}


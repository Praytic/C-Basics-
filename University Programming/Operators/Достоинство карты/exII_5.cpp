#include <iostream>
#include <cmath>

using namespace std;

int main()
{
// Включение распознавания русских символов
	setlocale(LC_ALL, "Russian");
	int n, m;
	cin >> n >> m;
// Вывод зависит от переменной m
	switch (m)
	{
		case 6: cout << "Шестерка ";  break;
		case 7: cout << "Семерка ";  break;
		case 8: cout << "Восьмерка ";  break;
		case 9: cout << "Девятка ";  break;
		case 10: cout << "Десятка ";  break;
		case 11: case 12: case 13:
		case 14: cout << "Картинка "; break;
		default: cout << "ERROR "; break;
	}
// Вывод зависит от переменной n
	switch (n)
	{
		case 1: cout << "пик" << endl; break;
		case 2: cout << "бубен" << endl; break;
		case 3: cout << "треф" << endl; break;
		case 4: cout << "червей" << endl; break;
		default: cout << "ERROR" << endl; break;
	}
}

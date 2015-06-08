#include <iostream>
#include <iomanip>

using namespace std;

// Заменение строки pi на константу 3.14159265359
const double lu = 1e-12;
const double pi = 3.14159265359;
// Если вещественное число близко к нулю на 12 и больше знаков, то приравнивает его к 0
#define if_lu(n) (n <= lu && n > 0.0 || n >= lu*(-1.0) && n < 0.0) ? 0.0 : n

double func1ex1(double i, double e, int &opCnt)
{
	double last = i;
	double result = i;
	for (int j = 1; abs(last) > e; j++)
	{
		last *= (i * i * (j * 2 - 1)) / ((j * 2 + 1) * (j * 2));
		result += last;
		opCnt++;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a = -0.9, b = 0.9;
	double h = 0.1;
	double e;
	int j = 1;
	cout << "Enter the precision: ";
	cin >> e;
// setiosglags(ios::left) - выравнивание по левому краю
// setw(n) - создание поля, в которой будет производиться вывод
	cout << setprecision(10) << setiosflags(ios::left) << setw(6) << "№№: " << setw(12) << "Значение x" << setw(24) << "Значение функции F(x)" << setw(21) << "Кол-во слагаемых n" << endl;
	for (double i = a; i <= b; i += h, j++)
	{
		int opCnt = 1;
		double func_res = func1ex1(i, e, opCnt);
		cout << setw(2) << j << setw(4) << ": " << setw(12) << (if_lu(i)) << setw(24) << pi / 2 - (if_lu(func_res)) << setw(21) << opCnt << endl;
	}
}

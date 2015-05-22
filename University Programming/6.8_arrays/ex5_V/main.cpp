#include <iostream>
#include <fstream>
// Эта библиотека содержит в себе функции для работы с несколькими переменными
#include <algorithm>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt");
ofstream out("outfile.txt");

int main()
{
	int a, k1, k2;
	in >> a >> k1 >> k2;
	int *mas1 = new int[a];
	if (k1 < 0 || k2 < 0 || k2 >= a || k1 >= a)
	{
		cout << "Error";
		return 0;
	}

	forn(i, a)
		in >> mas1[i];
	int g = 0;
	for (int i = 0; i < a; i++)
	{
// Функции min и max возвращают минимальный и максимальный элемент соответственно
	if ((i < min(k1, k2) && i >= 0) || (i>max(k1, k2) && i < a))
		{
			mas1[g] = mas1[i];
			g++;
		}
	}
	a -= abs(k2 - k1) + 1;
	forn(i, a)
		out << mas1[i] << ' ';
	delete[]mas1;
	return 0;
}

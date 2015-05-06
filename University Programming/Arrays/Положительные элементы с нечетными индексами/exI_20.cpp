#include <iostream>

using namespace std;

// Создание и считывание переменной в укороченной записи
#define ini(type, n) \
	type n; \
	cin >> n;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)

int main()
{
	ini(int, n);
	ini(int, m);
// Инициализация массива
	int mas1[100];
// Инициализация двумерного массива
	int mas2[100][100];
	if (m == 1)
	{
		forn(i, n) cin >> mas1[i];
		for (int i = 1; i < n; i += 2)
			cout << mas1[i] << ' ';
		cout << endl;
	}
	else
	{
		forn(i, n)
			forn(j, m) 
				cin >> mas2[i][j];
		for (int i = 1; i < n; i += 2)
		{
			for (int j = 1; j < m; j += 2)
			{
				cout << mas2[i][j] << ' ';
			}
			cout << endl;
		}
	}
}

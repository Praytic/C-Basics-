#include <iostream>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt");
ofstream out("outfile.txt");

int main()
{
	int a;
	in >> a;
// Объявление динамического массива и выделение памяти для первого столбца в нем
	int **mas3 = new int*[a];
	forn(i, a)
	{
// Выделение памяти под новую строку в массиве
		mas3[i] = new int[a];
		forn(j, a) in >> mas3[i][j];
	}
	bool sthHappened = false;
	forn(j, a)
	{
		int minj = mas3[0][j];
		int countMin = 0;
		forn(i, a)
		{
			if (minj > mas3[i][j])
			{
				minj = mas3[i][j];
				countMin = 1;
			}
			else if (minj == mas3[i][j])
				countMin++;
		}
		if (countMin != a)
		{
			sthHappened = true;
			forn(i, a) if (minj == mas3[i][j]) mas3[i][j] = 0;
		}
	}
	if (sthHappened) cout << "Success!";
	else cout << "Nothing changed.";
	forn(i, a)
	{
		forn(j, a) out << mas3[i][j] << ' ';
		out << endl;
	}
// Освобождение памяти, занимаемой массивом
	delete[] mas3;
	in.close();
	out.close();
}

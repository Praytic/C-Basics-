#include <iostream>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt");
ofstream out("outfile.txt");

int main()
{
	int a, b;
	bool nonull = true;
	bool sthHappened = false;
	in >> a >> b;
	int **mas3 = new int *[2 * a];
	forn(i, a)
	{
		mas3[i] = new int[b];
		forn(j, b)
		{
			in >> mas3[i][j];
		}
	}
	int *masSPEC = new int[b];
	forn(i, b)
		masSPEC[i] = 0;

	int linesAdded = 0;
	for (int i = 0; i < a + linesAdded; i++)
	{
		forn(j, b)
		{
			if (mas3[i][j] == 0)
				nonull = false;
		}
		if (nonull)
		{
			sthHappened = true;
			linesAdded++;
			i++;
			for (int k = a + linesAdded - 1; k > i; k--)
				mas3[k] = mas3[k - 1];
			mas3[i] = masSPEC;
		}
		nonull = true;
	}
	if (sthHappened)
		cout << "Something happened...";
	else
		cout << "Nothing happened.";
	forn(i, a + linesAdded)
	{
		forn(j, b)
		{
			out << mas3[i][j] << ' ';
		}
		out << endl;
	}
	delete[]mas3;
	in.close();
	out.close();
}

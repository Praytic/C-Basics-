#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt");
ofstream out("outfile.txt");

int main()
{
	int a;
	in >> a;
	int **mas3 = new int*[a];
	int **mas3_1 = new int*[a];
	forn(i, a)
	{
		mas3_1[i] = new int[2];
		mas3[i] = new int[a];
		forn(j, a) in >> mas3[i][j];
	}
	bool sthHappened = false;
	forn(j, a)
	{
		forn(i, a)
		{
			bool check = false;
			for (int k = i + 1; k < a; k++)
			{
				if (mas3[k][j] == mas3[i][j])
				{
					sthHappened = true;
					mas3_1[j][0] = i;
					mas3_1[j][1] = k;
					check = true;
					break;
				}
			}
			if (check)
				break;
		}
	}
	out << setiosflags(ios::left) << setw(16) << "First element: ";
	forn(i, a)
	{
		if (mas3_1[i][0] >= 0) out << mas3_1[i][0] << ' ';
		else out << "X ";
	}
	out << endl << setw(16) << "Second element: ";
	forn(i, a)
	{
		if (mas3_1[i][1] >= 0) out << mas3_1[i][1] << ' ';
		else out << "X ";
	}
	if (sthHappened) cout << "We found something.";
	else cout << "Pairs not found.";
	delete[] mas3_1;
	delete[] mas3;
	in.close();
	out.close();
}

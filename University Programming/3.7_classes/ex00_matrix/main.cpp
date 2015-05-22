#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

ifstream in("infile.txt");
ofstream out("outfile.txt");

int steps = 0;

class Matrix
{
private:
	int** arr;
	int n;
	int m;
public:
	Matrix() {}
	Matrix(ifstream& inp) {
		in >> n >> m;
		arr = new int*[n];
		forn(i, n) {
			arr[i] = new int[m];
			forn(j, m)
				in >> arr[i][j];
		}
	}
	Matrix(int a) {
		cin >> n >> m;
		arr = new int*[n];
		forn(i, n) {
			arr[i] = new int[m];
			forn(j, m)
				cin >> arr[i][j];
		}
	}
	Matrix(int** init, int n, int m)
	{
		this->n = n;
		this->m = m;
		int** use = new int*[n];
		for (int i = 0; i<n; i++)
		{
			use[i] = new int[m];
			for (int j = 0; j<m; j++)
				use[i][j] = init[i][j];
		}
		arr = use;
	}
	~Matrix() {
		cout << "Destructor apllied" << endl;
	}
	void clearMemory() {
		forn(i, n) delete[]arr[i];
		delete[]arr;
		cout << "Matrix has been destroyed" << endl;
	}
	void consolePrintMatrix() {
		forn(i, n) {
			cout << endl;
			forn(j, m) {
				cout << arr[i][j] << ' ';
			}
		}
		cout << endl;
	}
	void filePrintMatrix() {
		forn(i, n) {
			out << endl;
			forn(j, m) {
				out << arr[i][j] << ' ';
			}
		}
		out << endl;
	}
	string checkSymetry() {
		for (int i = 1; i< n - 1; i++)
			for (int j = 1; j< m - 1; j++)
				if (arr[i][m - j] != arr[n - i][j]) return "false";
		return "true";
	}
	void operator++();
	void operator--();
	Matrix operator+(Matrix second);
};

Matrix upload() {
	cout << "\nSTEP [" << steps++ << "]\n" << "How do you want to upload matrix? \n(1) file \n(2) console\nYour choise: ";
	ini(int, ways);
	if (ways == 1) {
		Matrix mat(in);
		return mat;
	}
	else if (ways == 2) {
		Matrix mat(0);
		return mat;
	}
	else
		upload();
}						// ii caaa?oaie? ooieoee ii?aio-oi i?eiaiyaony aano?oeoi?

bool operationToDo(Matrix& first, Matrix& second) {
	cout << "\nSTEP [" << steps++ << "]\n" << "What operation to do? \n(1) Increase by 1 \n(2) Decrease by 1 \n(3) Sum with other \n(4) Check the symetry \n(5) end\nYour choise: ";
	ini(int, ways);
	cout << "\nSTEP [" << steps++ << "]\n" << "Number of the matrix: \n(1) First matrix \n(2) Second matrix \nYour choise: ";
	ini(int, num);
	switch (ways) {
	case 1: (num == 1) ? first++ : second++; return true;
	case 2: (num == 1) ? first-- : second--; return true;
	case 3: (num == 1) ? first = first + second : second = first + second; return true;
	case 4: cout << ((num == 1) ? first.checkSymetry() : second.checkSymetry()) << endl; return true;
	case 5: return false;
	default: operationToDo(first, second);
	}
}

void printAll(Matrix first, Matrix second) {
	cout << "\nSTEP [" << steps++ << "]\n" << "How to print the matrixs? \n(1) file \n(2) console \nYour choise: ";
	ini(int, ways);
	switch (ways) {
	case 1: first.filePrintMatrix(); second.filePrintMatrix(); break;
	case 2: first.consolePrintMatrix(); second.consolePrintMatrix(); break;
	default: printAll(first, second);
	}
}

int main() {
	Matrix first = upload();
	Matrix second = upload();
	while (operationToDo(first, second));
	printAll(first, second);
	first.clearMemory();
	second.clearMemory();
	out.close();
	in.close();
}

void Matrix::operator++() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			arr[i][j]++;
	}
}

void Matrix::operator--() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++)
			arr[i][j]--;
}

Matrix Matrix::operator +(Matrix second)
{
	int** result = new int*[n];
	for (int i = 0; i<n; i++)
	{
		result[i] = new int[m];
		for (int j = 0; j<m; j++)
			result[i][j] = arr[i][j] + second.arr[i][j];
	}
	return Matrix(result, n, m);
}
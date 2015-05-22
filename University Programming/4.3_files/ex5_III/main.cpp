#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream intxt("infile.txt");

int main(){
	int n;
	intxt >> n;
	int a, b;
//Создание бинарного файла
	ofstream out("datfile.dat", ios::binary);
	forn(i, n){
		intxt >> a;
//Запись в бинарный файл
		out.write((char*)&a, sizeof(int));
	}
	out.close();
	ifstream in("datfile.dat", ios::binary);
	forn(i, n){
// Считывание с бинарного файла
		in.read((char*)&b, sizeof(int));
		if (b % 2 == 0)	cout << b << ' ';
	}
	cout << endl;
	out.close();
	intxt.close();
}

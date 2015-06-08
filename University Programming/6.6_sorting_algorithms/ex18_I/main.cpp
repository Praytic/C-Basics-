#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
    type n; \
	in >> n;

ofstream out("output.txt");
ifstream in("input.txt");

// Информационное поле студента
struct inf {
	string secondName;
	string firstName;
	string thirdName;
	int year;
	int marks[5];
	void scan();
	void print();
};

// Функция структуры выводит все данные о студенте
void inf::print(){
	out << secondName << ' ' << firstName << ' ' << thirdName << ' ' << year <<' ';
	forn(j, 5) out << marks[j] << ' ';
	out << endl;
}

// Функция структуры считывает все данные о студенте
void inf::scan(){
	in >> secondName >> firstName >> thirdName >> year;
		forn(j,5) in >> marks[j];
}

// Функция производит сортировку данных группы по
// фамилиям, именам, отчествам студентов методом выбора
void f(vector<inf> &a, int n) {
	forn(i, n-1) {
		int num = i;
		// Начиная с i-ого элемента ищем минимальный элемент
		// из всех элементов впереди i-ого и меняем местами найденный
		// элемент и i-ый.
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j].secondName < a[num].secondName) num = j;
				else if (a[j].firstName < a[num].firstName) num = j;
					else if (a[j].thirdName < a[num].thirdName) num = j;
		}
		swap(a[i], a[num]);
	}
}

int main() {
	ini(int, n);
	vector<inf> vec(n); 
	forn(i, n)	vec[i].scan();
	f(vec, n);
	forn(i, n)	vec[i].print();
	fclose(stdout);
	in.close();
	out.close();
	return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long

ofstream out("output.txt");
ifstream in("input.txt");

struct inf {
	string secondName, firstName, thirdName;
	int year, marks;
	void scan();
	void print();
};
void inf::print(){
	out << secondName << ' ' << firstName << ' ' << thirdName << ' ' << year << ' ' << marks;
	out << endl;
}
void inf::scan(){
	int a;
	marks = 0;
	in >> secondName >> firstName >> thirdName >> year;
		forn(j,5) {
			in >> a;
			marks+= a;
		}
}
// Функция сортирует данные студентов по убыванию
// суммы оценок методом пузырька
void f(vector<inf> &a, int n) {
	for (int i = a.size() - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (a[j].marks < a[j-1].marks) 
				swap(a[j], a[j-1]);
		}
	}
}

int main() {
	vector<inf> vec; 
	// Считывание данных при неизвестном их количестве
	forn(i, vec.size()+1)	{
		if (!in.eof()) vec.resize(vec.size()+1);
		else break;
		vec[i].scan();
	}
	// Сортировка и вывод в файл
	f(vec, vec.size());
	forn(i, vec.size())	
		vec[i].print();
	in.close();
	out.close();
	return 0;
}


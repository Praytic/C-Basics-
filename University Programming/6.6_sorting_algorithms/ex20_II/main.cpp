#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
    type n; \
	in >> n;

ofstream out("output.txt");
ifstream in("input.txt");

// Функция сортировки массива методом вставок
void sorting(vector<int> &a, int l, int r) {
	int i, j, temp;
	for (i = l+1; i <= r; i++) {
		temp = a[i];
		for (j = i - 1; j >= l; j--) {
			// В зависимости от расположения сортируемого массива,
			// будут разные условия для выхода из цикла (первое -
			// для элементов выше побочной диагонали, второе -
			// для элементов ниже побочной диагонали)
			if (l == 0 && a[j] > temp)
				break;
			else if (r == a.size()-1 && a[j] < temp)
				break;
			a[j + 1] = a[j];
			a[j] = temp;
		}
	}
}

int main() {
	ini(int, n);
	vector<vector<int>> vec(n, vector<int>(n));
	forn(i, n)
		forn(j, n)
		in >> vec[i][j];
	//Сортируем элементы выше побочной диагонали
	for (int i = 0; i < vec.size()-1; i++) {
		sorting(vec[i], 0, n-i-2);
	}
	//Сортируем элементы ниже побочной диагонали
	for (int i = 1; i < vec.size(); i++) {
		sorting(vec[i], n - i, n-1);
	}

	forn (i, n) {
		forn(j, n-i-1)
			out << vec[i][j] << ' ';
		out << "X ";
		for (int j = n-i; j < n; j++)
			out << vec[i][j] << ' ';
		out << endl;
	}
	in.close();
	out.close();
	return 0;
}


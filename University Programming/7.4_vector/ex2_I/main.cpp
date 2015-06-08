#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// Предикат для функции replace_if, который
// проверяет аргумент на четность
bool f(int i) {
	return i & 1;
}
// Предикат для функции for_each
void fcin(int &i) {
	cin >> i;
}

int main()
{
    int n, tochange;
    cout << ">number of elements: ";
    cin >> n;
    cout << ">enter x: ";
	cin >> tochange;
    cout << ">elements: ";
	vector<int> a(n);
	// Считывание функцией for_each
	for_each(a.begin(), a.end(), fcin);
	// Функция заменяет все нечетные числа на введеное пользователем
	replace_if(a.begin(), a.end(), f, tochange);
    cout << ">result: ";
	// Вывод элементов вектора через итераторы
    for (vector<int>::iterator i = a.begin(); i != a.end(); i++) {
        cout << *i << ' ';
    }
    return 0;
}


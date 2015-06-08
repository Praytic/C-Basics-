#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int x;
// Предикат функции find_if проверяет аргумент
// на равенство первой цифры числа и х
bool f(int i) {
	return abs(i % 10) == x;
}
void fcin(int &i) {
	cin >> i;
}
void fcout(int i) {
	cout << i << ' ';
}
int main()
{
	int n, c;
	cout << ">number of elements: ";
	cin >> n;
	cout << ">enter x: ";
	cin >> x;
	cout << ">enter inserting element: ";
	cin >> c;
	cout << ">elements: ";
	vector<int> a(n);
	for_each(a.begin(), a.end(), fcin);
	// Итерационный цикл вставляет элемент c после всех
	// элементов, последняя цифра которых равна x
	for (vector<int>::iterator it = a.begin(); find_if(it, a.end(), f) != a.end();) {
		// Пока в векторе от итератора it до конца вектора
		// есть элементы, удовлетворяющие условию из предиката f
		// будем вставлять значение c после таких элементов
		it = a.insert(find_if(it, a.end(), f) +1, c) + 1;
	}
	cout << ">result: ";
	for_each(a.begin(), a.end(), fcout);
	return 0;
}
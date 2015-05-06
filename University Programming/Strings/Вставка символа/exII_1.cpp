#include <iostream>
// Подключение заголовочного файла, включающего в себя функции для работы со строками
#include <string>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
#define ini(type, n) \
	type n; \
	cin >> n;

int main() {
	cout << "Enter the string: ";
	string s;
// Считывание строки до знака переноса
	getline(cin, s);
	cout << "Enter the sensor: ";
	ini(char, c1);
	cout << "Enter the insert: ";
	ini(char, c2);
	forn(i, s.size())
		if (s[i] == c1) {
// Вставка элемента в строку
		s.insert(s.begin() + i + 1, c2);
		i++;
		}
	cout << "Result: " << s << endl;
}

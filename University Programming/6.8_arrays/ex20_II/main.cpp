#include <iostream>
// Заголовочный файл fstream позволяет производить действия над файлами
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
// Определение потока для входных данных
ifstream in("input.txt");
// Определение потока для выходных данных
ofstream out("output.txt");

int main()
{
	double mas2[1000];
	int a;
	int result = 0;
// Считывание с файла
	in >> a;
	forn(i, a)
		in >> mas2[i];
	forn(i, a - 1)
		if (mas2[i] < mas2[i + 1])
			result++;
// Вывод в файл
	out << result;
	if (result <= a && result >= 0)
		cout << "Success!";
// Закрываем файлы
	in.close();
	out.close();
}

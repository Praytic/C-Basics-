#include <iostream>
#include <string>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
#define ini(type, n) \
	type n; \
	cin >> n;

string clear_spaces(string s)
{
	if (s[0] == ' ' && s.find_first_not_of(' ') < s.size())
// Удаление части строки
		s.erase(s.begin(), s.begin() + s.find_first_not_of(' '));
	if (s[s.size() - 1] == ' ' && s.find_last_not_of(' ') < s.size())
		s.erase(s.begin() + s.find_last_not_of(' ') + 1, s.end());
	if (s.find_first_not_of(' ') >= s.size() && s.find_last_not_of(' ') >= s.size())
		return "";

	forn(i, s.size() - 1)
	{
		if (s[i] == s[i + 1] && s[i] == ' ')
		{
			s.erase(s.begin() + i);
			i--;
		}
	}
	forn(i, s.size() - 1)
	{
		if (s[i] == ' ' && ispunct(s[i + 1]))
			s.erase(s.begin() + i);
	}
	return s;
}

int main()
{
	string mas1[100];
	string real_mas[100];
	string s;
	getline(cin, s, '.');
	int cini = 0;
	int am = 0;
	while (cini < s.size())
	{
// Проверяем, является ли символ пробелом или знаком-разделителем
		if (ispunct(s[cini]) || (isspace(s[cini])))
		{
			if (cini > 0 && !(ispunct(s[cini - 1]) || (isspace(s[cini - 1]))))
				am++;
		}
		else
		{
			real_mas[am] += s[cini];
// Меняем регистр алфавитного символа на строчный
			mas1[am] += tolower(s[cini]);
		}
		cini++;
	}
	forn(i, am)
	{
		for (int j = i + 1; j <= am; j++)
		{
			if (real_mas[j] == "")
				break;
			if (mas1[i] == mas1[j])
			{
// Поиск совпадений подстроки в строке s
				int index = s.find(" " + real_mas[i]);
				s.erase(s.begin() + index, s.begin() + index + real_mas[i].size()+1);
				real_mas[i] = "";
			}
		}
	}
	cout << clear_spaces(s) << endl;
}

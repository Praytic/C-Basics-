#include <iostream>
#include <string>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
#define ini(type, n) \
	type n; \
	cin >> n;

int main()
{
	string s[100];
	int cini = 0;
	while (cin)
	{
		cin >> s[cini++];
// Проверка следующего символа
		if (cin.peek() == '\n')
			break;
	}
	double digits[100];
	int num_digit = 0;
	forn(i, cini)
	{
		bool onepoint = false;
		bool canbe = true;
		forn(j, s[i].size())
		{
			if (isdigit(s[i][j]) || s[i][j] == '.')
			{
				if (s[i][j] == '.' && (onepoint || j == s[i].size() - 1))
				{
					canbe = false;
					break;
				}
				else if (s[i][j] == '.')
					onepoint = true;
			}
			else
			{
				canbe = false;
				break;
			}
		}
		if (canbe)
		{
			digits[num_digit] = stod(s[i]);
			num_digit++;
		}
	}
	cout << "Doubles' found: ";
	forn(i, num_digit)
		cout << digits[i] << ' ';
	cout << endl;
}

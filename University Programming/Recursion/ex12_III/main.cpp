#include <iostream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

void stars(int n, int temp) {
	// ��������� ��� �������� ����� ������� � ��������
	if (n != 0) {
		forn(i, temp)
			cout << '*';
		forn(i, n)
			cout << ' ';
		forn(i, temp)
			cout << '*';
		cout << endl;
		stars(n - 2, temp + 1);
	}
	// ��� �������� ����������� ����� ������� �� ��������
	forn(i, temp)
		cout << '*';
	forn(i, n)
		cout << ' ';
	forn(i, temp)
		cout << '*';
	cout << endl;
}

int main()
{
	ini(int, n);
	stars(n, 1);
}

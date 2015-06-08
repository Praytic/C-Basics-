#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	for (int i = 100; i<1000; i++)
	{
if ((i % 10 == i % 100 / 10 || i % 10 == i / 100 || i % 100 / 10 == i / 100) && (i / 100>0 && i / 100<10)) 
cout << i << ' ';
	}
	cout << endl << "----------------" << endl;
	{
		int a, b;
		cin >> a >> b;
		int i = a;
		while (i <= b)
		{
if ((i % 10 == i % 100 / 10 || i % 10 == i / 100 || i % 100 / 10 == i / 100) && (i / 100>0 && i / 100<10))
cout << i << ' ';
			i++;
		}
	}
	cout << endl << "----------------" << endl;
	{
		int a, b;
		cin >> a >> b;
		int i = a;
		do
		{
if ((i % 10 == i % 100 / 10 || i % 10 == i / 100 || i % 100 / 10 == i / 100) && (i / 100>0 && i / 100<10)) 
	cout << i << ' ';
			i++;
		} while (i <= b);
	}
}

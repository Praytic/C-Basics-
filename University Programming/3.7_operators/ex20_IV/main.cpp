#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	for (int i = 5; i >= 1; i--)
	{
		for (int j = 0; j<i; j++)
			cout << 2 << ' ';
		cout << endl;
		for (int j = 0; j<i; j++)
			cout << j + i - 2 << ' ';
		cout << endl;
	}
}

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c;
	cout << "Type a, b, c: ";
	cin >> a >> b >> c; 
// Применение тернарной операции
	cout << (a == b && b == c ? "YES" : "NO") << endl;	
}

#include <iostream>
#include <cmath> 	

using namespace std;

int main()
{
	double b1, q, n;
	cout << "Type b1, devisor and count: ";
	cin >> b1 >> q >> n;
	cout << "Solution: " << (b1*(pow(q, n) - 1) / (q - 1)) << endl;
}

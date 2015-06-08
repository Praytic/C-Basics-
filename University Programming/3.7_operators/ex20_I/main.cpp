#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double x1, y1;
	cout << "Type coordinates: ";
	cin >> x1 >> y1;
// Применение логических операций
if (-23 <= x1 && x1 <= 0 && 0 <= y1 && y1 <= 23 && (y1*1.0 / x1 <= -1.0 || x1 == 0))
		if (x1 == 0 || y1 == 23 || y1*1.0 / x1 == -1.0)
			cout << "On the border" << endl;
		else cout << "Yes" << endl;
	else cout << "No" << endl;
}

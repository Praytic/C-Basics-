#include <iostream>
#include <memory>

using namespace std;
int a[10001], b[10001], n, e, i;

bool could(int i, int j) {
	if (b[i] && b[i] != j) return 0;
	if (b[i]) return 1;
	b[i] = j;
	if (!could(j, a[i])) b[i] = 0;
	return b[i];
}
int main() {
	cin >> n;
	for (i = 1; i <= n; i++) cin >> a[i];

	for (i = 1; i <= n; i++)
		if (!b[i])
		{
		e = 0;
		for (int j = 1; j <= n; j++)
			if (could(i, j))
			{
			e = 1;
			break;
			}

		if (!e)
		{
			cout << "No solution"; return 0;
		}
		}

	for (i = 1; i <= n; i++) cout << b[i] << " ";
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

//ofstream out("outfile.txt");
//ifstream in("infile.txt");

int mas[100000];

int f(int t, int mas[], int n) {
	int s = 0;
	forn(i, n) {
		s += mas[i] / t;
	}
	return s;
}

int main() {
	ini(int, n);
	ini(int, k);
	int l = 1;
	int r = 10e5;
	forn(i, n) {
		cin >> mas[i];
		//r = max(r, mas[i]);
	}

	int weightNum = 0;
	int maxMid = 0;
	while (r - l >= 1) {
		int mid = (l + r) / 2;
		weightNum = f(mid, mas, n);
		if (weightNum >= k && mid > maxMid) {
			maxMid = mid;
			l = mid;
		}
		else
			r = mid;
	}
	cout << maxMid << endl;
	//out.close();
	//in.close();
}

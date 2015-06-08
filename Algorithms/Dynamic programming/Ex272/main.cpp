#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>

using namespace std;
const double lu = 1e-8;
const double pi = 3.14159265359;
#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

int main(){
	ini(int, n);
	ini(int, m);
	vector<int> vec(n);
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (i - m >= 0)
			vec[i] = max(vec[i - m] + vec[i], vec[i - 1]);
		if (i - 1 >= 0)
			vec[i] = max(vec[i], vec[i - 1]);
	}
	cout << vec[vec.size() - 1] << endl;
}
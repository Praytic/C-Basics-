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

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

int main(){
	ini(int, n);
	vector<int> vec(n*3+1, INT_MAX);
	vec[0] = 0;
	vec[1] = 0;
	vector<int> operation(n*3+1, 1);
	for (int i = 1; i <= n; i++){
		if (vec[i] > vec[i - 1] + i) {
			vec[i] = i + vec[i - 1];
			operation[i] = 1;
		}
		if (operation[i * 2] < 2){
			operation[i * 2] = 2;
			vec[i * 2] = min(i * 2 + vec[i], vec[i * 2]);
		}
		if (operation[i * 3] < 3){
			operation[i * 3] = 3;
			vec[i * 3] = min(i * 3 + vec[i], vec[i * 3]);
		}
	}
	cout << vec[n] << endl;
	while (n != 1) {
		if (operation[n] == 1) {
			cout << "-1 ";
			n--;
		}
		if (operation[n] == 2) {
			cout << "/2 ";
			n /= 2;
		}
		if (operation[n] == 3) {
			cout << "/3 ";
			n /= 3;
		}
	}
	cout << endl;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include "time.h"

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

void Merge(vector<int> a, int s, int f, int m, vector<int> &temp) {
	int i = s, j = m + 1, k = s;
	while ((i <= m) && (j <= f)) {
		if (a[i] <= a[j]) {
			temp[k] = a[i];
			i++;
		}
		else {
			temp[k] = a[j];
			j++;
		}
		k++;
	}
	while (i <= m) {
		temp[k] = a[i];
		i++;
		k++;
	}
	while (j <= f) {
		temp[k] = a[j];
		j++;
		k++;
	}
}

void BottomUpMergesort(vector<int> &a) {
	vector<int> temp = a;
	for (int i = 1; i < a.size(); i *= 2) {
		for (int j = 0; j < a.size(); j += 2 * i) 	{
			int s = j;
			int m = j + (i - 1);
			if (m >= a.size()) {
				m = a.size() - 1;
			}
			int f = j + ((2 * i) - 1);
			if (f >= a.size()) {
				f = a.size() - 1;
			}
			Merge(a, s, f, m, temp);
		}
		a = temp;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	forn(i, n) cin >> a[i];
	BottomUpMergesort(a);
	forn(i, n) cout << a[i] << ' ';
	
}
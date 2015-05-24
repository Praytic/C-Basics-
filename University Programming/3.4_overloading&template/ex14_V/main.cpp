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
#include "math.h"

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

template <typename x>
void printMatrix(vector<vector<x>> vec)
{
	forn(i, vec.size()) {
		cout << endl;
		forn(j, vec[i].size())
		cout << vec[i][j] << ' ';
	}
}

template <typename x>
void mainFunction(vector<vector<x>> vec) {
	cout << "Enter the size: ";
	ini(int, n);
	ini(int, m);
	vec.resize(n);
	cout << "Enter the matrix: " << endl;
	forn(i, n)
		vec[i].resize(m);
	forn(i, n) 
		forn(j, m)
			cin >> vec[i][j];
	problemSolution(vec, n, m);
	printMatrix(vec);
}

template <typename x>
void problemSolution(vector<vector<x>> &vec, int n, int m) {
	double middleSum = 0;
	int cnt = 0;
	int nm = min(n, m);
	for (int i = (n - nm) / 2; i < n; i++) {
		for (int j = max((m - nm) / 2 + nm - (i - ((n - nm) / 2)) - 1, 0); j < m; j++) {
			middleSum += vec[i][j];
			vec[i][j] = 0;
			cnt++;
		}
	}
	cout << "\nSolution: " << ((n*m==max(n,m)) ? 0 : middleSum/cnt) << "\n";
}

bool chooseType() {
	vector<vector<ll>> vec1;
	vector<vector<double>> vec2;
	cout << "Type of matrix:\n[1] long long\n[2] double\n";
	ini(char, answer);
	switch (answer) {
	case '1': mainFunction(vec1); return true;
	case '2': mainFunction(vec2); return true;
	}
	return false;
}

int main() {
	while (!chooseType());
	return 0;
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include "time.h"

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

char mas[9][9];
int cube[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};
int line[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};
int column[9][9] = {{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9},{1,2,3,4,5,6,7,8,9}};
vector<int> cube1(9);
vector<int> line1(9);
vector<int> column1(9);
int i, j;
int zeros = 0;
bool stoppls = false;

void rec(int l) {
	if (zeros == 0 || stoppls) {
		stoppls = true;
		return;
	}
	for(; l<81; l++) {
		i = l/9;
		j = l%9;
		if (mas[i][j] == '0') {
			forn(k,9)
			if (cube[((i+1)*9+j+1)/9+!!(((i+1)*9+j+1)%9)-i%3-(8-j)/3][k] == column[j][k] && line[i][k] == column[j][k] && line[i][k] == k+1) {
				cube[((i+1)*9+j+1)/9+!!(((i+1)*9+j+1)%9)-i%3-(8-j)/3][k]=0;
				column[j][k]=0;
				line[i][k]=0;
				mas[i][j] = k+1+'0';
				zeros--;
					rec(l+1);
				if (stoppls) return;
				zeros++;
				i = l/9;
				j = l%9;
				cube[((i+1)*9+j+1)/9+!!(((i+1)*9+j+1)%9)-i%3-(8-j)/3][k]=k+1;
				column[j][k]=k+1;
				line[i][k]=k+1;
				mas[i][j] = '0';
			}
			return;
		}
	}
}

int main()
{
	forn(i1, 9)
		forn(j1, 9) {
			cin >> mas[i1][j1];
			int a = (int)mas[i1][j1] - 48;
			if (a != 0) {
				cube[((i1+1)*9+j1+1)/9+!!(((i1+1)*9+j1+1)%9)-i1%3-(8-j1)/3][a-1] = 0;
				line[i1][a-1] = 0;
				column[j1][a-1] = 0;
			}
			else zeros++;
	}
	forn(i1, 9) {
		bool check = false;
		forn(j1, 9) {
			if (cube[i1][j1] != 0) {
				cube1[cube[i1][j1]-1]++;
				check = true;
			}
		}
		if (!check) cube1.push_back(0);
	}
	forn(i1, 9) {
		bool check = false;
		forn(j1, 9) {
			if (line[i1][j1] != 0) {
				line1[line[i1][j1]-1]++;
				check = true;
			}
		}
		if (!check) line1.push_back(0);
	}
	forn(i1, 9) {
		bool check = false;
		forn(j1, 9) {
			if (column[i1][j1] != 0) {
				column1[column[i1][j1]-1]++;
				check = true;
			}
		}
		if (!check) column1.push_back(0);
	}
	rec(0);
		forn(i1,9) {
			forn(j1,9)
			cout << mas[i1][j1];
			cout << endl;
		}
}
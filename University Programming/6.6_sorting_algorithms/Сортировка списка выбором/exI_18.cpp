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
	in >> n;

ofstream out("output.txt");
ifstream in("input.txt");


struct inf {
	string secondName;
	string firstName;
	string thirdName;
	int year;
	int marks[5];
	void scan();
	void print();
};

void inf::print(){
	out << secondName << ' ' << firstName << ' ' << thirdName << ' ' << year <<' ';
	forn(j, 5) out << marks[j] << ' ';
	out << endl;
}

void inf::scan(){
	in >> secondName >> firstName >> thirdName >> year;
		forn(j,5) in >> marks[j];
}

void f(vector<inf> &a, int n) {
	forn(i, n-1) {
		int num = i;
		for (int j = i + 1; j < a.size(); j++) {
			if (a[j].secondName < a[num].secondName) num = j;
				else if (a[j].firstName < a[num].firstName) num = j;
					else if (a[j].thirdName < a[num].thirdName) num = j;
		}
		swap(a[i], a[num]);
	}
}

int main() {
	ini(int, n);
	vector<inf> vec(n); 
	forn(i, n)	vec[i].scan();
	f(vec, n);
	forn(i, n)	vec[i].print();
	fclose(stdout);
	in.close();
	out.close();
	return 0;
}
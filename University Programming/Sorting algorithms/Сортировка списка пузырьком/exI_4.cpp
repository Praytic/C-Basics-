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
	int marks;
	void scan();
	void print();
};

void inf::print(){
	out << secondName << ' ' << firstName << ' ' << thirdName << ' ' << year << ' ' << marks;
	out << endl;
}

void inf::scan(){
	int a;
	marks = 0;
	in >> secondName >> firstName >> thirdName >> year;
		forn(j,5) {
			in >> a;
			marks+= a;
		}
}

void f(vector<inf> &a, int n) {
	for (int i = a.size() - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			if (a[j].marks < a[j-1].marks) 
				swap(a[j], a[j-1]);
		}
	}
}

int main() {
	ini(int, n);
	vector<inf> vec; 
	forn(i, vec.size()+1)	{
		if (!in.eof()) vec.resize(vec.size()+1);
		else {
			vec.pop_back();
			break;
		}
		vec[i].scan();
	}
	f(vec, vec.size());
	forn(i, vec.size())	
		vec[i].print();
	fclose(stdout);
	in.close();
	out.close();
	return 0;
}
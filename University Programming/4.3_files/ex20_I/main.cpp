#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt"); 
ofstream out("outfile.txt");

int main() {
	string s;
	while (in.peek() != EOF) {
		string sNew = "";
		getline(in, s);  
		forn(i, s.length())
			if (i % 2 == 0) sNew += (char)s[i];
		out << sNew << endl;
	}
	in.close();
	out.close();
}

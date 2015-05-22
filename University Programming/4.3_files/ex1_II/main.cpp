#include <iostream>
#include <string>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("f.txt"); 
ofstream out("g.txt");
ofstream out2("h.txt");

int main(){
	int cini;
	while (in.peek() != EOF) {
		in >> cini; 
if (cini % 2 == 0)
			out << cini << ' ';
		else
			out2 << cini << ' ';

	}
	in.close();
	out.close();
	out2.close();
}

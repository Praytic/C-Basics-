#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
#define ini(type, n) \
	type n; \
	cin >> n;
ifstream in("infile.txt");
ofstream out("outfile.txt");

struct passed {
	string name[3];
	int course;
	int group;
	double result;
	void print(double);
};
// Член-функция для вывода строки с уловием
void passed::print(double n){
	if (result <= n)
		out << setiosflags(ios::left) << setw(14) << name[0] + " " + name[1] + " " + name[2] << setw(7) << course << setw(9) << group << setw(9) << result << endl;
}

int main(){
	string s;
	passed stru;
	ini(double, n);
	getline(in, s, '\n');
	out << s << endl;
	while(in.peek() != EOF){
		in >> stru.name[0] >> stru.name[1] >> stru.name[2] >> stru.course >> stru.group >> stru.result;
		stru.print(n);
	}
}

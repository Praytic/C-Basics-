#include "pstack.h"

ifstream in("input.txt");

int main() {
	PStack custom1, custom2, custom3;
	string s;
	while(!in.eof()) {
		in >> s;
		custom1.push(s);
		custom2.push(s);
	}
	int num = 0;
	string correctTop = custom1.pop();
	while(!custom2.empty()) {
		string compare = custom2.pop();
		if (correctTop == compare) {
			num++;
		}
		else {
			custom3.push(compare);
		}
	}
	custom3.push(correctTop);
	while(!custom3.empty()) {
		cout << custom3.pop() << ' ';
	}
	cout << endl << num - 1 << endl;
	return 0;
}

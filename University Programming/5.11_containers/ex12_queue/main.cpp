#include "pqueue.h"

ifstream in("input.txt");

int main() {
	PQueue custom1, custom2;
	string topElement, compareElement;
	while (!in.eof()) {
		in >> topElement;
		custom1.PPut(topElement);
	}
	int num = 0;
	custom1.PGet();
	while (!custom1.PEmpty()) {
		compareElement = custom1.PGet();
		if (topElement == compareElement) {
			num++;
		}
		else {
			custom2.PPut(compareElement);
		}
	}
	custom2.PPut(topElement);
	cout << num << endl;
	while (!custom2.PEmpty()) {
		cout << custom2.PGet() << ' ';
	}
	return 0;
}

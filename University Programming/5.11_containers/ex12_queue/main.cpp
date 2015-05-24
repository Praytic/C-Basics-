#include "pqueue.h"

ifstream in("input.txt");

int main() {
	PQueue custom1, custom2;
	string topElement, compareElement;
	// Каждый новый считываемый элемент будет последним
	while (!in.eof()) {
		in >> topElement;
		custom1.PPut(topElement);
	}
	int num = 0;
	// Производим те же действие, что и со стеком
	while (!custom1.PEmpty()) {
		compareElement = custom1.PGet();
		if (topElement == compareElement) {
			num++;
		}
		else {
			custom2.PPut(compareElement);
		}
	}
	// Кладем в очередь последний считанный элемент,
	// так как нам нужно его сохранить и вычитаем из
	// num 1, потому что программа посчитала все совпадения
	custom2.PPut(topElement);
	cout << num - 1 << endl;
	while (!custom2.PEmpty()) {
		cout << custom2.PGet() << ' ';
	}
	return 0;
}

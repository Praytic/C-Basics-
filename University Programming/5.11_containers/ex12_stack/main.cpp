#include "pstack.h"

ifstream in("input.txt");

int main() {
	PStack custom2, custom1;
	string s;
	// Заполнение стека считанной строкой
	while (!in.eof()) {
		in >> s;
		custom2.push(s);
	}
	int num = 0;
	// Сохраняем верхний элемент стека и удаляем его из
	// второго стека и добавляем его в первый, так как
	// нам нужно сохранить его, а его совпадения удалить
	string correctTop = custom2.pop();
	custom1.push(correctTop);

	// Пока второй стек не будет пуст, будем брать верхний
	// элемент и сравнивать с correctTop, и если они будут
	// различны, то добавим элемент из custom2 в custom3
	// Таким образом, все совпадающие элементы с correctTop
	// не войдут в новый стек и получится такойже стек custom3,
	// но уже без элементов, совпадающих с верхним
	while (!custom2.empty()) {
		string compare = custom2.pop();
		if (correctTop == compare) {
			num++;
		}
		else {
			custom1.push(compare);
		}
	}
	while (!custom1.empty()) {
		cout << custom1.pop() << ' ';
	}
	cout << endl << num - 1 << endl;
	return 0;
}

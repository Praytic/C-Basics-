#include "psinglelist.h"

int main() {
	int num = 0;
	string s, topString;
	// Заводим список типа string
	PSingleList<string> custom;
	// Считываем все элементы в строке
	custom.PRowInsert();
	// Удаление всех элементов, равных topString
	cout << custom.PRowRemove() << endl;
	custom.PPrint();
}

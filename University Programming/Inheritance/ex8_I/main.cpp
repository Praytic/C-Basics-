#include "inheritance.h"
#include "persona.h"
#include "organization.h"
#include "friend.h"

using namespace std;

const int INDEX = 100000;
const int INDEX_ORG = 1000;
ifstream in ("input.txt");

int main()
{
	setlocale( LC_ALL,"Russian" );
	// Создаем массив экземпляров класса
	TelephoneDirectory *customSpreadsheet[1000];
    int i = 0;
	string A1, A2, A3, A4, A5, A6, A7, A8;
	// Считываем данные для Persona
    while (!in.eof()) {
		in >> A1;
		if (A1 == ">Organization")
			break;
        in >> A2 >> A3;
        customSpreadsheet[i++] = new Persona(i + INDEX, A1, A2, A3);
	}
	// Считываем данные для Organization
	while (!in.eof()) {
		in >> A1;
		if (A1 == ">Friend")
			break;
		in >> A2 >> A3 >> A4 >> A5 >> A6 >> A7;
		customSpreadsheet[i++] = new Organization(i + INDEX_ORG, i + INDEX, A1, A2, A3, A4, A5, A6, A7);
	}
	// Считываем данные для Friend
	while (!in.eof()) {
		in >> A1 >> A2 >> A3 >> A4;
		customSpreadsheet[i++] = new Friend(i + INDEX_ORG, i + INDEX, A1, A2, A3, A4);
	}
	customSpreadsheet[i] = nullptr;
	i = 0;
	// Выводим все считанные данные в стандартный поток
	while (customSpreadsheet[i] != nullptr) {
		customSpreadsheet[i++]->PShow();
	}
	string searchingElement;
	// Выводим данные, удовлетворяющие поиску в стандартный поток
	while(true) {
		cout << "\n\nВведите фамилию для поиска (exit - для выхода): ";
		cin >> searchingElement;
		if (searchingElement == "exit") break;
		i = 0;
		while (customSpreadsheet[i] != nullptr) {
			customSpreadsheet[i++]->PCheck(searchingElement);
		}
	}
    return 0;
}
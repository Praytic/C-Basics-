#ifndef PERSONA_H
#define PERSONA_H

#include "inheritance.h"
// Наследование от абстрактного класса
class Persona: public TelephoneDirectory {
protected:
	int ID;
    string firstName;
    string secondName;
    string telephoneNumber;
public:
	Persona():  
		ID(999999),
		firstName("UNKNOWN"),
		secondName("UNKNOWN"),
		telephoneNumber("UNKNOWN") {}
	Persona(int A1, string A2, string A3, string A4):
		ID(A1),
		firstName(A3),
		secondName(A2),
		telephoneNumber(A4) {}
    ~Persona() {}
	// Метод выводит данные класса в стандартный поток
    void PShow() {
		cout << "[" << ID << "] "
			<< firstName << ' '
			<< secondName << ' '
			<< telephoneNumber << endl;
    }
	// Метод возвращает значение поля secondName
	string PSecondName() {
		return secondName;
	}
	// Метод проверяет входной аргумент и secondName
	// и выводит данные на экран при совпадении
    void PCheck(string compareElement) {
        if (compareElement == secondName)
            PShow();
    }
};

#endif // PERSONA_H

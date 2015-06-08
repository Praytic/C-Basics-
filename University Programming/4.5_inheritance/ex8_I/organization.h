#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "persona.h"

class Organization : public TelephoneDirectory {
protected:
	int ID;
	Persona custom;
	string name;
	string adress;
	string telephoneNumber;
	string fax;
public:
	Organization():
		ID(999999),
		name("UNKNOWN"),
		adress("UNKNOWN"),
		telephoneNumber("UNKNOWN"),
		fax("UNKNOWN") {
		Persona();
	}
	Organization(int A0, int A1, string A2, string A3, string A4, string A5, string A6, string A7, string A8):
		ID(A0),
		name(A2),
		adress(A3),
		telephoneNumber(A4),
		fax(A5) {
		custom = Persona(A1, A6, A7, A8);
	}
	Organization(int A0, Persona A1, string A2, string A3, string A4, string A5):
		ID(A0),
		custom(A1),
		name(A2),
		adress(A3),
		telephoneNumber(A4),
		fax(A5) {
	}
	~Organization() {}
	
	// Метод выводит данные текущего экземпляра класса и
	// экземпляра custom в стандартный поток
	void PShow() {
		cout << "[" << ID << "] "
			<< name << ' '
			<< adress << ' '
			<< telephoneNumber << ' '
			<< fax << " Contact: ";
		custom.PShow();
	}
	// Метод производит поиск по фамилии в поле
	// экземпляра класса custom
	void PCheck(string compareElement) {
		if (compareElement == custom.PSecondName())
			PShow();
	}
};

#endif // ORGANIZATION_H

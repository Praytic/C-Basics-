#ifndef PERSONA_H
#define PERSONA_H

#include "inheritance.h"

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
		firstName(A2),
		secondName(A3),
		telephoneNumber(A4) {}
    ~Persona() {}

    void PShow() {
		cout << "[" << ID << "] "
			<< firstName << ' '
			<< secondName << ' '
			<< telephoneNumber << endl;
    }

	string PSecondName() {
		return secondName;
	}

    void PCheck(string compareElement) {
        if (compareElement == secondName)
            PShow();
    }
};

#endif // PERSONA_H

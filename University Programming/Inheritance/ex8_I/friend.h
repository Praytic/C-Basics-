#ifndef FRIEND_H
#define FRIEND_H

#include "persona.h"

class Friend : public TelephoneDirectory {
protected:
	int ID;
	Persona custom;

	string birthdayDate;
public:
	Friend() :
		ID(999999),
		birthdayDate("UNKNOWN") {
		Persona();
	}
	Friend(int A0, int A1, string A2, string A3, string A4, string A5) :
		ID(A0),
		birthdayDate(A5) {
		custom = Persona(A1, A2, A3, A4);
	}
	Friend(int A0, Persona A1, string A2) :
		ID(A0),
		custom(A1),
		birthdayDate(A2) {}
	~Friend() {}

	void PShow() {
		cout << "[" << ID << "] "
			<< birthdayDate
			<< " Friend: ";
		custom.PShow();
	}

	void PCheck(string compareElement) {
		if (compareElement == custom.PSecondName())
			PShow();
	}
};

#endif // FRIEND_H

#ifndef PERSONA_H
#define PERSONA_H

#include "inheritance.h"

class Persona: public TelephoneDirectory {
protected:
    struct data {
        string firstName;
        string secondName;
        string telephoneNumber;

        data () :
            firstName("UNKNOWN"),
            secondName("UNKNOWN"),
            telephoneNumber("UNKNOWN") {}

        data (string D1, string D2, string D3) :
            firstName(D1),
            secondName(D2),
            telephoneNumber(D3) {}
    };
public:
    Persona(): ID(NULL), data() {}
    Persona(int A1, string A2, string A3, string A4): ID(A1), data(A2, A3, A4) {}
    ~Persona() {}

    void PShow() {
        cout << "[" << index << "] "
             << firstName << ' '
             << secondName << ' '
             << telephoneNumber << endl;
    }

    void PCheck(string compareElement) {
        if (compareElement == secondName)
            PShow();
    }
};

#endif // PERSONA_H

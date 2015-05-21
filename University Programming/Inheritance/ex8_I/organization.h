#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "persona.h"

class Organization: public Persona {
protected:
    struct data {
        string name;
        string adress;
        string telephoneNumber;
        string fax;

        data () :
            name("UNKNOWN"),
            adress("UNKNOWN"),
            telephoneNumber("UNKNOWN"),
            fax("UNKNOWN"){}

        data (string D1, string D2, string D3, string D4) :
            name(D1),
            adress(D2),
            telephoneNumber(D3),
            fax(D4){}
    };
public:
    Organization(): ID(NULL), Persona(), data() {}
    Organization(int A1, string A2, string A3, string A4, string A5, string A6, string A7, string A8):
        ID(A1),
        Persona(A1, A2, A3, A4),
        data(A5, A6, A7, A8) {}
    Organization(int A1, Persona A2, string A3, string A4, string A5, string A6):
        ID(A1),
        Persona(A1, A2.data.firstName, A2.data.secondName, A2.data.telephoneNumber),
        data(A3, A4, A5, A6) {}
    ~Organization() {}

    void PShow() {
        cout << "[" << index << "] "
             << name << ' '
             << adress << ' '
             << telephoneNumver << ' '
             << fax << ' '
             << " Contact: "
             << firstName << ' '
             << secondName << ' '
             << telephoneNumber << endl;
    }

    void PCheck(string compareElement) {
        if (compareElement == secondName)
            PShow();
    }
};

#endif // ORGANIZATION_H

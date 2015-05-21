#ifndef FRIEND_H
#define FRIEND_H

#include "persona.h"

class Friend: public Persona {
protected:
    struct data {
        string birthdayDate;
        data () :
            birthdayDate("UNKNOWN"){}
        data (string D1) :
            birthdayDate(D1){}
    };
public:
    Friend(): ID(NULL), Persona(), data() {}
    Friend(int A1, string A2, string A3, string A4, string A5):
        ID(A1),
        Persona(A1, A2, A3, A4),
        data(A5) {}
    Friend(int A1, Persona A2, string A3, string A4, string A5, string A6):
        ID(A1),
        Persona(A1, A2.data.firstName, A2.data.secondName, A2.data.telephoneNumber),
        data(A3) {}
    ~Friend() {}

    void PShow() {
        cout << "[" << index << "] "
             << firstName << ' '
             << secondName << ' '
             << telephoneNumber << ' '
             << birthdayDate << endl;
    }

    void PCheck(string compareElement) {
        if (compareElement == secondName)
            PShow();
    }
};

#endif // FRIEND_H

//#ifndef FRIEND_H
//#define FRIEND_H
//
//#include "persona.h"
//
//class Friend: public Persona {
//protected:
//    struct PData {
//        string birthdayDate;
//        PData () :
//            birthdayDate("UNKNOWN"){}
//        PData (string D1) :
//            birthdayDate(D1){}
//    };
//public:
//    Friend(): ID(NULL), Persona(), PData() {}
//    Friend(int A1, string A2, string A3, string A4, string A5):
//        ID(A1),
//        Persona(A1, A2, A3, A4),
//        PData(A5) {}
//    Friend(int A1, Persona A2, string A3, string A4, string A5, string A6):
//        ID(A1),
//        Persona(A1, A2.PData.firstName, A2.PData.secondName, A2.PData.telephoneNumber),
//        PData(A3) {}
//    ~Friend() {}
//
//    void PShow() {
//        cout << "[" << index << "] "
//             << firstName << ' '
//             << secondName << ' '
//             << telephoneNumber << ' '
//             << birthdayDate << endl;
//    }
//
//    void PCheck(string compareElement) {
//        if (compareElement == secondName)
//            PShow();
//    }
//};
//
//#endif // FRIEND_H

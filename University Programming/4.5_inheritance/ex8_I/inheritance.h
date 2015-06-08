#ifndef INHERITANCE_H
#define INHERITANCE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Абстрактный класс
class TelephoneDirectory {
public:
    virtual void PShow() = 0;
    virtual void PCheck(string s) = 0;
};

#endif // INHERITANCE_H

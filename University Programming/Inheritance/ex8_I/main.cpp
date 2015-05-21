#include "inheritance.h"

using namespace std;

const int INDEX = 100000;
ifstream in ("input.txt");

int main()
{
    vector<Persona> customSpreadsheet;
    int i = 0;
    while (!in.peek() != '>') {
        cin >> A1 >> A2 >> A3 >> A4;
        customSpreadsheet.push_back(TelephoneDirectory(INDEX + i, A1, A2, A3, A4));
    }
    return 0;
}


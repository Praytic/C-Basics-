#include "inheritance.h"
#include "persona.h"
#include "organization.h"
#include "friend.h"

using namespace std;

const int INDEX = 100000;
const int INDEX_ORG = 1000;
ifstream in ("input.txt");

int main()
{
	TelephoneDirectory *customSpreadsheet[1000];
    int i = 0;
	string A1, A2, A3, A4, A5, A6, A7, A8;
    while (!in.eof()) {
		in >> A1;
		if (A1 == ">Organization")
			break;
        in >> A2 >> A3;
        customSpreadsheet[i++] = new Persona(i + INDEX, A1, A2, A3);
	}
	while (!in.eof()) {
		in >> A1;
		if (A1 == ">Friend")
			break;
		in >> A2 >> A3 >> A4 >> A5 >> A6 >> A7;
		//if (isdigit(A5[0]))
		//	customSpreadsheet[i] = new Organization(i, customSpreadsheet *[stoi(A5) - INDEX], A1, A2, A3, A4);
		customSpreadsheet[i++] = new Organization(i + INDEX_ORG, i + INDEX, A1, A2, A3, A4, A5, A6, A7);
	}
    return 0;
}


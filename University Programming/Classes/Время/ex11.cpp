//#include <iostream>
//#include <vector>
//#include <ctime>
//#include <fstream>
//#include <string>
#include "classtime.h"

//using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)

ifstream in("input.txt");

int main()
{
    classTime basicTime, compareTime, compareTime2;
    while (!in.eof()) {
		char typingCommand;
		if (in.peek() == '*') {
			in.ignore(256, '\n');
			continue;
		}
		else
			in >> typingCommand;
        switch(typingCommand) {
		case '1': basicTime.setTheTime(in); 
				  break;
		case '2': basicTime.showTheTimeFormed(); 
				  break;
		case '3': compareTime.setTheTime(in); 
				  basicTime.afterTheTime(compareTime); 
				  break;
		case '4': compareTime.setTheTime(in); 
				  compareTime2.setTheTime(in);
				  basicTime.betweenTheTime(compareTime, compareTime2); 
				  break;
		case '5': classTime::showCurrentMaxMin();
				  return 0;
		default:  cout << "string [" << classTime::stringNumber << "] unknown command: " << typingCommand << endl;
				  in.ignore(256, '\n');
        }
		classTime::stringNumber++;
    }
}


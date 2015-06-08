#include "classtime.h"

#define forn(i, n) for (int i = 0; i < n; i++)

ifstream in("input.txt");

int main()
{
	// Создание экземпляров класса classTime
    classTime basicTime, compareTime, compareTime2;
    while (!in.eof()) {
		// Считываем первый символ строки
		// Если считываемый символ является *, то вся
		// информация после этого символа - это комментарий,
		// и считывать ее не надо
		char typingCommand;
		if (in.peek() == '#') {
			in.ignore(256, '\n');
			continue;
		}
		else
			in >> typingCommand;
		// В зависимости от введенной команды будут
		// выполняться определенные действия.
		// Если команда не находится в пределах 1 и 5,
		// то она введена не верно и выведется сообщение
		// об ошибке
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


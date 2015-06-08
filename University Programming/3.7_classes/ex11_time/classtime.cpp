#include "classtime.h"

#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long

ofstream out("output.txt");

// Инициализация статических полей класса
int classTime::stringNumber = 1;
classTime classTime::maxTime;
classTime classTime::minTime(24, 60, 60);

// Статическая функция выводит в поток макс. и мин.
// время, которое было найдено (запускается в конце
// программы)
void classTime::showCurrentMaxMin() {
	out << "max time: ";
	maxTime.showTheTime();
	out << endl;
	out << "min time: ";
	minTime.showTheTime();
	out << endl;
}

// Функция устанавливает время объекта
// согласно данным, которые ввел пользователь
void classTime::setTheTime(ifstream &in)
{
	string strTime1;
	int intTime2 = 0;
	in >> strTime1;
	forn(i, strTime1.size()) {
		// Во время считывания времени, все должно
		// быть по образцу ЧЧ:ММ:СС. Если считанное
		// время не удовлетворяет образцу, то будет
		// выведенно сообщение об ошибке и запись не произойдет
		if (i < 8) {
			if (!(isdigit(strTime1[i]) && ((i + 1) % 3 != 0))) {
				if (!((strTime1[i] == ':') && ((i + 1) % 3 == 0))) {
					out << stringNumber << "> " << "wrong parameters: " << strTime1 << endl;
					return;
				}
				else 
					continue;
			}
			else 
				intTime2 = intTime2*10 + (strTime1[i] - '0');
		}
		else {
			out << stringNumber << "> " << "wrong parameters: " << strTime1 << endl;
			return;
		}
	}

	// Если данные введены некорректно
	// (минут или секунд больше 60), то
	// присваивания не произойдет и программа
	// перейдет к следующему действию
	if ((intTime2 / 10000 >= 24) || ((intTime2 / 100) % 100 >= 60) || (intTime2 % 100 >= 60)) {
		out << stringNumber << "> " << "wrong parameters: " << strTime1 << endl;
		return;
	}
	
	// Устанавливаем считанное время полям
	// текущего объекта и заодно обновляем
	// макс. и мин. время
	this->hours = intTime2 / 10000;
	this->minutes = (intTime2 / 100) % 100;
	this->seconds = intTime2 % 100;
	classTime compareTime(hours, minutes, seconds);
	if (compareTime > maxTime)
		maxTime = compareTime;
	if (compareTime < minTime)
		minTime = compareTime;
}

// Функция выводит поля текущего экземпляра класса
void classTime::showTheTime()
{
	out << hours / 10 << hours % 10 << ':'
		<< minutes / 10 << minutes % 10 << ':'
		<< seconds / 10 << seconds % 10;
}

// Функция выводит поля текущего экземпляра класса
// с нужным форматированием
void classTime::showTheTimeFormed()
{
	out << stringNumber << "> " << "current time is "
		<< hours / 10 << hours % 10 << ':'
		<< minutes / 10 << minutes % 10 << ':'
		<< seconds / 10 << seconds % 10 << endl;
}

// Функция вычисляет сколько будет времени
// после заданного кол-ва часов, минут, секунд
// и вызывает функцию вывода результата
void classTime::afterTheTime(classTime varTime1)
{
	classTime varTime2 = *this;
	varTime2 = varTime1 + varTime2;
	out << stringNumber << "> " << "the time after ";
	varTime1.showTheTime();
	out << " will be ";
	varTime2.showTheTime();
	out << endl;
}

// Функция вычисляет сколько должно пройти
// времени в указанном пользователем промежутке
// и вызывает функцию вывода результата
void classTime::betweenTheTime(classTime varTime1, classTime varTime2)
{
	out << stringNumber << "> " << "the time between ";
	varTime1.showTheTime();
	out << " and ";
	varTime2.showTheTime();
	out << " is ";
	if (varTime2 < varTime1)
		varTime2 = varTime1 - varTime2;
	else 
		varTime2 = varTime2 - varTime1;
	varTime2.showTheTime();
	out << endl;
}
// Перегрузка оператора <
bool classTime::operator <(classTime varTime1)
{
	return (hours*10000 + minutes*100 + seconds < varTime1.hours*10000 + varTime1.minutes*100 + varTime1.seconds);
}
// Перегрузка оператора >
bool classTime::operator >(classTime varTime1)
{
	return (hours*10000 + minutes*100 + seconds > varTime1.hours*10000 + varTime1.minutes*100 + varTime1.seconds);
}
// Перегрузка оператора + c учетом ограничений
classTime classTime::operator +(classTime varTime1)
{
	varTime1.hours = ((hours + varTime1.hours) % 24 + (minutes + varTime1.minutes + (seconds + varTime1.seconds) / 60) / 60) % 24;
	varTime1.minutes = ((minutes + varTime1.minutes) % 60 + (seconds + varTime1.seconds) / 60) % 60;
	varTime1.seconds = (seconds + varTime1.seconds) % 60;
	return varTime1;
}
// Перегрузка оператора - c учетом ограничений
classTime classTime::operator -(classTime varTime1)
{
	if (seconds - varTime1.seconds >= 0) 
		varTime1.seconds = seconds - varTime1.seconds;
	else {
		varTime1.seconds = 60 + seconds - varTime1.seconds; 
		varTime1.minutes++;
	}
	if (minutes - varTime1.minutes >= 0) 
		varTime1.minutes = minutes - varTime1.minutes;
	else {
		varTime1.minutes = 60 + minutes - varTime1.minutes; 
		varTime1.hours++;
	}
	varTime1.hours = abs(hours - varTime1.hours)%24;
	return varTime1;
}

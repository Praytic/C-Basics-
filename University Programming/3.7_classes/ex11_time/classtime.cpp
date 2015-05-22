#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include "classtime.h"

using namespace std;

#define forn(i, n) for (int i = 0; i < n; i++)
#define ll long long

ofstream out("output.txt");

int classTime::stringNumber = 1;
classTime classTime::maxTime;
classTime classTime::minTime(24, 60, 60);

void classTime::showCurrentMaxMin() {
	out << "max time: ";
	maxTime.showTheTime();
	out << endl;
	out << "min time: ";
	minTime.showTheTime();
	out << endl;
}

//Как считывать по образцу? Типа scanf("%d:%d", &a, &b)
void classTime::setTheTime(ifstream &in)
{
	string strTime1;
	int intTime2 = 0;
	in >> strTime1;
	forn(i, strTime1.size()) {
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
	if ((intTime2 / 10000 >= 24) || ((intTime2 / 100) % 100 >= 60) || (intTime2 % 100 >= 60)) {
		out << stringNumber << "> " << "wrong parameters: " << strTime1 << endl;
		return;
	}
	
// Как сравнить значения класса от которого вызывается функция?
	
	this->hours = intTime2 / 10000;
	this->minutes = (intTime2 / 100) % 100;
	this->seconds = intTime2 % 100;
	classTime compareTime(hours, minutes, seconds);
	if (compareTime > maxTime)
		maxTime = compareTime;
	if (compareTime < minTime)
		minTime = compareTime;
}

void classTime::showTheTime()
{
	out << hours / 10 << hours % 10 << ':'
		<< minutes / 10 << minutes % 10 << ':'
		<< seconds / 10 << seconds % 10;
}

void classTime::showTheTimeFormed()
{
	out << stringNumber << "> " << "current time is "
		<< hours / 10 << hours % 10 << ':'
		<< minutes / 10 << minutes % 10 << ':'
		<< seconds / 10 << seconds % 10 << endl;
}

void classTime::afterTheTime(classTime varTime1)
{
	classTime varTime2(hours, minutes, seconds);
	varTime2 = varTime1 + varTime2;
	out << stringNumber << "> " << "the time after ";
	varTime1.showTheTime();
	out << " will be ";
	varTime2.showTheTime();
	out << endl;
}

// Как присвоить значение классу от которого вызывается функция?
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

bool classTime::operator <(classTime varTime1)
{
	return (hours*10000 + minutes*100 + seconds < varTime1.hours*10000 + varTime1.minutes*100 + varTime1.seconds);
}

bool classTime::operator >(classTime varTime1)
{
	return (hours*10000 + minutes*100 + seconds > varTime1.hours*10000 + varTime1.minutes*100 + varTime1.seconds);
}

classTime classTime::operator +(classTime varTime1)
{
	varTime1.hours = ((hours + varTime1.hours) % 24 + (minutes + varTime1.minutes + (seconds + varTime1.seconds) / 60) / 60) % 24;
	varTime1.minutes = ((minutes + varTime1.minutes) % 60 + (seconds + varTime1.seconds) / 60) % 60;
	varTime1.seconds = (seconds + varTime1.seconds) % 60;
	return varTime1;
}

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

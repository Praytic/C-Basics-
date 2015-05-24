#ifndef CLASSTIME_H
#define CLASSTIME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

class classTime
{
public:
	// Конструкторы класса
	classTime() : hours(0), minutes(0), seconds(0) {}
	classTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
	// Методы класса
    void showTheTime();
	void showTheTimeFormed();
    void setTheTime(ifstream &in);
	void afterTheTime(classTime varTime1);
	void betweenTheTime(classTime varTime1, classTime varTime2);
	static void showCurrentMaxMin();
	// Перегруженные операторы
	classTime operator +(classTime varTime1);
	classTime operator -(classTime varTime1);
	bool operator <(classTime varTime1);
	bool operator >(classTime varTime1);
	// Статические поля класса
	static classTime maxTime;
	static classTime minTime;
	static int stringNumber;
private:
	// Поля класса
    int hours;
    int minutes;
    int seconds;
};

#endif

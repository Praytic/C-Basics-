#ifndef CLASSTIME_H
#define CLASSTIME_H

#include <iostream>
#include <vector>
#include <ctime>
#include <fstream>
#include <string>
#include "classtime.h"

using namespace std;

class classTime
{
public:
	classTime() : hours(0), minutes(0), seconds(0) {}
	classTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    void showTheTime();
	void showTheTimeFormed();
    void setTheTime(ifstream &in);
	void afterTheTime(classTime varTime1);
	void betweenTheTime(classTime varTime1, classTime varTime2);
	static void showCurrentMaxMin();

	classTime operator +(classTime varTime1);
	classTime operator -(classTime varTime1);
	bool operator <(classTime varTime1);
	bool operator >(classTime varTime1);

	static classTime maxTime;
	static classTime minTime;
	static int stringNumber;
private:
    int hours;
    int minutes;
    int seconds;
};

#endif

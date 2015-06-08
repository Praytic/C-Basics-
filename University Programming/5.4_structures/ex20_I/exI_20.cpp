#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
#define forn(i,n) for(unsigned int i = 0; i < n; i++)
ifstream in("infile.txt");
// Создание структуры
struct point {
	double x;
	double y;
	double z;
};

double funcDistance(int i, int j, point mas1[100]){
double returned = sqrt((mas1[j].x - mas1[i].x)*(mas1[j].x - mas1[i].x) + (mas1[j].y - mas1[i].y)*(mas1[j].y - mas1[i].y) + mas1[j].z - mas1[i].z)*(mas1[j].z - mas1[i].z));
	return returned;
}

bool checkPoints(double x, double y, double z){
	if ((x == y + z) || (y == x + z) || (z == x + y))
		return true;
	return false;
}

int main(){
	point mas1[100];
	point thisPoints[3];
	double thisDistances[3];
	int cini = 0;
	while (in.peek() != EOF){
		in >> mas1[cini].x >> mas1[cini].y >> mas1[cini].z;
		cini++;
	}
	int P = 1;
	double minDistance = DBL_MAX;
	for (int i = 0 + 0; i < cini; i++){
		for (int j = i + 1; j < cini; j++){
			for (int l = j + 1; l < cini; l++){
				thisDistances[0] = funcDistance(i, j, mas1);
				thisDistances[1] = funcDistance(j, l, mas1);
				thisDistances[2] = funcDistance(l, i, mas1);
	if (checkPoints(thisDistances[0], thisDistances[1], thisDistances[2])) continue;
if (minDistance >= thisDistances[0] + thisDistances[1] + thisDistances[2]){
					thisPoints[0] = mas1[i];
					thisPoints[1] = mas1[j];
					thisPoints[2] = mas1[l];
minDistance = thisDistances[0] + thisDistances[1] + thisDistances[2];
cout << "P[" << P << "] = " << minDistance << endl;
					P++;
				}
			}
		}
	}
	cout << endl;
cout << "A(" << thisPoints[0].x << ", " << thisPoints[0].y << ", " << thisPoints[0].z << ")\n";
cout << "B(" << thisPoints[1].x << ", " << thisPoints[1].y << ", " << thisPoints[1].z << ")\n";
cout << "C(" << thisPoints[2].x << ", " << thisPoints[2].y << ", " << thisPoints[2].z << ")\n";
	cout << "\nP[FINAL] = " << minDistance << endl;
}

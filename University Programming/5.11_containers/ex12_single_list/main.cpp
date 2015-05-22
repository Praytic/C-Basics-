#include "psinglelist.h"

int main() {
	int num = 0;
	string s, topString;
	PSingleList<string> custom;
	custom.PRowInsert();
	cout << custom.problemSolver(custom) << endl;
	custom.PPrint();
}
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <ctime>
#include <memory>
#include <fstream>

using namespace std;

#pragma warning(disable : 4996)
#define forn(i, n) for(size_t i = 0; i < n; i++)
typedef long long ll;
typedef long double ld;

ld n;
string result;
char c;
string s;
ll a, b;
int pos;

string convertToString(ld n) {
	string s = "";
	bool negative = false;
	if (n < 0) {
		negative = true;
		n *= (-1);
	}
	ll part1 = (ll)n;
	ld part2 = n - abs(part1);

	//part2 = modf(n, &part1);

	if (part1 != 0)
		while (part1 != 0) {
		s += part1 % 10 + '0';
		part1 /= 10;
		}
	else s += '0';


	if (negative)
		s += '-';
	reverse(s.begin(), s.end());
	if (part2 != 0) s += '.';

	int check = 0;
	while (part2 != 0 && check != 5) {
		s += ll(part2 * 10) + '0';
		part2 = part2 * 10;
		ll llpart = (ll)part2;
		part2 -= llpart;
		check++;
	}
	return s;
}

ld convertToDouble(string s) {
	ld a = 0;
	bool point = false;
	bool negative = false;
	ld j = 1;
	forn(i, s.size()) {
		if (isdigit(s[i]))
			a = a * 10 + (s[i] - '0');

		if (isdigit(s[i]) && point) {
			j *= 10;
		}

		if (s[i] == '.') {
			point = true;
		}
		if (s[i] == '-') {
			negative = true;
		}
	}
	ld result2 = a / j + 1e-10;
	if (negative) result2 *= (-1);
	return result2;
}

string operations(string s, ld n);

string uniqueSubstr(string s) {
	int firstPos = s.find('(');
	int flag = 1;
	int i = firstPos + 1;
	while (flag != 0) {
		if (s[i] == '(') flag++;
		else if (s[i] == ')') flag--;
		i++;
	}
	int secondPos = i;

	return s.substr(firstPos + 1, secondPos - (firstPos + 2));
}

string rec(string s, ld n) {
	while (s.find(')') != string::npos) {
		result = rec(uniqueSubstr(s), n);
		int position = s.find('(');
		s.erase(s.begin() + s.find('('), s.begin() + s.find(')') + 1);
		s.insert(position, result);
	}

	return operations(s, n);
}

int main() {

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	cin >> b;
	cin >> s;
	ld realResult;
	cout << convertToDouble(operations(rec(s, b), b));
	//pos = 0;
	//realResult -= convertToDouble(operations(rec(s, a), a));
	//cout << realResult << endl;
	return 0;
}

/////////////////// OPERATIONS ////////////////////////

string operations(string s, ld n) {

	while (true) {
		int i = 0;
		bool breakCheck = false;
		while (s.find('x') != string::npos) {
			int position = s.find('x');
			s.erase(s.begin() + s.find('x'));
			s.insert(position, convertToString(n));

			if (s.find("x") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find('^') != string::npos) {
			ld firstVar;
			ld secondVar;

			int rightPos = 0;
			int leftPos = s.size();

			if (isdigit(s[s.find('^') - 1])) {
				i = s.find('^') - 1;
				string newDigit = "";
				while (i >= 0 && (isdigit(s[i]) || s[i] == '.'))
					newDigit = s[i--] + newDigit;
				firstVar = convertToDouble(newDigit);
				leftPos = min(leftPos, i + 1);
			}

			if (isdigit(s[s.find('^') + 1]) || s[s.find('^') + 1] == '-') {
				i = s.find('^') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('^') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				secondVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			ld increase = firstVar;
			if ((int)secondVar > 0)
				forn(j, (int)secondVar - 1) {
				firstVar *= increase;
			}
			else if ((int)secondVar < 0) {
				for (int j = (int)secondVar; j <= 0; j++) {
					firstVar /= increase;
				}
				firstVar += 1e-10;
			}
			else firstVar = 1;
			s.insert(leftPos, convertToString(firstVar));

			if (s.find("^") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find("sqrt") != string::npos) {
			ld firstVar;

			int rightPos = 0;
			int leftPos = s.find("sqrt");

			if (isdigit(s[s.find('t') + 1]) || s[s.find('t') + 1] == '-') {
				i = s.find('t') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('t') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				firstVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(sqrt(firstVar)));

			if (s.find("sqrt") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find("cos") != string::npos) {
			ld firstVar;

			int rightPos = 0;
			int leftPos = s.find("cos");

			if (isdigit(s[s.find("cos") + 3]) || s[s.find("cos") + 3] == '-') {
				i = s.find("cos") + 3;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find("cos") + 4)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				firstVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(cos(firstVar)));

			if (s.find("cos") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find("sin") != string::npos) {
			ld firstVar;

			int rightPos = 0;
			int leftPos = s.find("sin");

			if (isdigit(s[s.find("sin") + 3]) || s[s.find("sin") + 3] == '-') {
				i = s.find("sin") + 3;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find("cos") + 4)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				firstVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(cos(firstVar)));

			if (s.find("sin") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find('*') != string::npos) {
			ld firstVar;
			ld secondVar;

			int rightPos = 0;
			int leftPos = s.size();

			if (isdigit(s[s.find('*') - 1])) {
				i = s.find('*') - 1;
				string newDigit = "";
				while (i >= 0 && (isdigit(s[i]) || s[i] == '.'))
					newDigit = s[i--] + newDigit;
				firstVar = convertToDouble(newDigit);
				leftPos = min(leftPos, i + 1);
			}

			if (isdigit(s[s.find('*') + 1]) || s[s.find('*') + 1] == '-') {
				i = s.find('*') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('*') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				secondVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(firstVar*secondVar));

			if (s.find("*") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find('+') != string::npos) {
			ld firstVar;
			ld secondVar;

			int rightPos = 0;
			int leftPos = s.size();

			if (isdigit(s[s.find('+') - 1])) {
				i = s.find('+') - 1;
				string newDigit = "";
				while (i >= 0 && (isdigit(s[i]) || s[i] == '.'))
					newDigit = s[i--] + newDigit;
				firstVar = convertToDouble(newDigit);
				leftPos = min(leftPos, i + 1);
			}

			if (isdigit(s[s.find('+') + 1]) || s[s.find('+') + 1] == '-') {
				i = s.find('+') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('+') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				secondVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(firstVar + secondVar));

			if (s.find("+") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find('-') != string::npos && s.find('-') != 0) {
			ld firstVar;
			ld secondVar;

			int rightPos = 0;
			int leftPos = s.size();

			if (isdigit(s[s.find('-') - 1])) {
				i = s.find('-') - 1;
				string newDigit = "";
				while (i >= 0 && (isdigit(s[i]) || s[i] == '.'))
					newDigit = s[i--] + newDigit;
				firstVar = convertToDouble(newDigit);
				leftPos = min(leftPos, i + 1);
			}

			if (isdigit(s[s.find('-') + 1]) || s[s.find('-') + 1] == '-') {
				i = s.find('-') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('-') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				secondVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(firstVar - secondVar));

			if (s.find('-') == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		while (s.find('/') != string::npos) {
			ld firstVar;
			ld secondVar;

			int rightPos = 0;
			int leftPos = s.size();

			if (isdigit(s[s.find('/') - 1])) {
				i = s.find('/') - 1;
				string newDigit = "";
				while (i >= 0 && (isdigit(s[i]) || s[i] == '.'))
					newDigit = s[i--] + newDigit;
				firstVar = convertToDouble(newDigit);
				leftPos = min(leftPos, i + 1);
			}

			if (isdigit(s[s.find('/') + 1]) || s[s.find('/') + 1] == '-') {
				i = s.find('/') + 1;
				string newDigit = "";
				while (i < s.size() && (isdigit(s[i]) || s[i] == '.' || (s[i] == '-' && i == s.find('/') + 1)))
					newDigit = s[i++] + newDigit;
				reverse(newDigit.begin(), newDigit.end());
				secondVar = convertToDouble(newDigit);
				rightPos = max(rightPos, i);
			}

			s.erase(s.begin() + leftPos, s.begin() + rightPos);
			s.insert(leftPos, convertToString(firstVar / secondVar));

			if (s.find("/") == string::npos) breakCheck = true;
		}
		if (breakCheck) continue;

		if (!breakCheck) break;
	}


	return s;
}
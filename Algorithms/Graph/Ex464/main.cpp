#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
    type n; \
	in >> n;

ofstream out("output.txt");
ifstream in("input.txt");

vector<vector<vector<pair<int, int>>>> g(8, vector<vector<pair<int, int>>>(8));
string s;

bool cantCross(int i, int j) {
	char a = i+'A';
	char b = j+'1';
	string step = "";
	step += a;
	step += b;
	if (s.find(step) != string::npos)
		return false;
	else return true;
}

void add(int i, int j, int p1, int p2) {
	if (i+p1 < 8 && j+p2 < 8 && i+p1 > 0 && j+p2 > 0) {
		if (cantCross(i+p1, j+p2) && cantCross(i, j)) {
			g[i][j].push_back(make_pair(i+p1,j+p2));
			g[i+p1][j+p2].push_back(make_pair(i,j));
		}
	}
	
}

int main() {
	pair<int, int> start, finish;
	char al;
	int bl;
	cin >> al >> bl;
	start.first = al-'A';
	start.second = bl-1;
	cin >> al >> bl;
	finish.first = al-'A';
	finish.second += bl-1;

	cin >> s;
	forn(i, 8) {
		forn(j, 8) {
			add(i, j, 1, 2);
			add(i, j, 2, 1);
			add(i, j, -1, -2);
			add(i, j, -2, -1);
			add(i, j, -1, 2);
			add(i, j, 1, -2);
			add(i, j, -2, 1);
			add(i, j, 2, -1);
		}
	}
		
	queue<pair<int, int>> q;
	vector<vector<bool>> used (8, vector<bool>(8));
	vector<vector<int>> d (8, vector<int>(8));
	vector<vector<pair<int, int>>> p (8, vector<pair<int, int>>(8));
	q.push (start);
	used[start.first][start.second] = true;
	p[start.first][start.second] = make_pair(-1, -1);
	while (!q.empty()) {
		pair<int, int> v = q.front();
		q.pop();
		for (int i = 0; i < g[v.first][v.second].size(); ++i) {
			pair<int, int> to = g[v.first][v.second][i];
			if (!used[to.first][to.second]) {
				used[to.first][to.second] = true;
				q.push(to);
				d[to.first][to.second] = d[v.first][v.second] + 1;
				p[to.first][to.second] = v;
			}
		}
	}
	

	if (!used[finish.first][finish.second])
		cout << 0;
	else {
		string path = "";
		for (pair<int, int> v = finish; v != make_pair(-1, -1); v = p[v.first][v.second]) {
			char a = v.first + 'A';
			char b = v.second + '1';
			path += b;
			path += a;
		}
		reverse (path.begin(), path.end());
		cout << path << endl;
	}
	return 0;
}
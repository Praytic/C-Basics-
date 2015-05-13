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

using namespace std;

#define forn(i,n) for(int i = 0; i < n; i++)
#define ll long long
#define ini(type, n) \
	type n; \
	cin >> n;

using namespace std;

int findPos(vector<int> a, vector<int> b)
{
	vector<vector<int> > pos(a.size()+1, vector<int>(b.size()+1));
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j])
			{
				pos[i + 1][j + 1] = 1 + pos[i][j];
			}
			else
			{
				pos[i + 1][j + 1] = max(pos[i][j + 1], pos[i + 1][j]);
			}
		}
	}
	return pos[a.size()][b.size()];
}

int main(){
	ini(int, a);
	ini(int, b);
	vector<int> vec1(a);
	vector<int> vec2(b);
	forn(i, a) cin >> vec1[i];
	forn(i, b) cin >> vec2[i];
	cout << findPos(vec1, vec2) << endl;
}
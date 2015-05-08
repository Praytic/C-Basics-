﻿#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <iostream>
#include <algorithm>
 
#define forn(i, n)		for(int i = 0; i < n; i++)
#define mp(a, b)		make_pair(a, b) 
#define all(a)			(a).begin(), (a).end()
typedef long long ll;
const int N = (int)1e7;
 
using namespace std;
 
//ifstream cin("input.txt");
//ofstream cout("output.txt");
 
vector<pair<int, int>> p;			//вектор всех сотрудников с макс.
						//боссом и расстоянием до него
pair<int, int> find_leader(int v) {
    if(v == p[v].first)				//если боссом сотрудника является
		return p[v];			//он сам, то ничего не меняется
    else {						
        if (p[p[v].first].second != 0) {			//иначе, если у босса сотрудника
            pair<int, int> up = find_leader(p[v].first);	//существует свой босс, то устанавливаем
            p[v].first = up.first ;				//сотруднику босса повыше и расстояние
            p[v].second += up.second;				//до макс. босса будет равно сумме
        }							//расстояний от пред. до след. босса
        return p[v];
    }
}					//функция возвращает пару <макс. босс, расстояние до него>
					//для указанного сотрудника
void union_leaders(int a, int b) {		
    a = find_leader(a).first;		//находим номер макс. босса для
    b = find_leader(b).first;		//сотрудника и его босса
 
    if(a != b) {					//если такой макс. босс у них 
        p[a].first = b;					//не одинаковый, то устанавливаем
        p[a].second += find_leader(b).second + 1;	//для сотрудника его макс. босса
    }							//и расстояние до него
}

struct edge {
    int first, second;
    ll cost;
};
 
int main() {
    int n, m;
    cin >> n >> m;
 
    p = vector<pair<int, int>> (n);		//вектор боссов, в котором в начале
    forn(i, n) p[i].first = i;			//каждый человек является боссом
						//самому себе и расстояние до босса = 0
    forn(i, m) {
        int type;
        cin >> type;
        if(type == 1) {				//считываем комманду. Если 1, то
            int a, b;				//устанавливаем макс. босса сотруднику a
            cin >> a >> b;
            a--; b--;
            union_leaders(a, b);
        }
        else {					//Если 2, то выводим текущее расстояние
            int a;				//до макс. босса сотрудника a
            cin >> a;
            a--;
            find_leader(a);
            cout << p[a].second << endl;
        }
    }
    return 0;
}

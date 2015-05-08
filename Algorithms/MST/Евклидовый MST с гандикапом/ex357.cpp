#include <map>
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
typedef ll				long long;
const int INF = (int)1e7;
 
using namespace std;
 
//ifstream cin("input.txt");
//ofstream cout("output.txt");
 
struct edge {
	int first, second;
	int cost;
};
 
int leng(const pair<int, int> &a, const pair<int, int> &b) {	// функция подсчитывает расстояние
    return (a.first - b.first) * (a.first - b.first) +			// от двух точек и возвращает его
		   (a.second - b.second) * (a.second - b.second);		// квадрат.
}
 
int main() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> cor(n);		//вектор всех вершин
    forn(i, n)
        cin >> cor[i].first >> cor[i].second;
    cin >> m;
    set<pair<int, int>> edge;			//сет готовых рёбрышек
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b)
            swap(a, b);
        edge.insert(make_pair(a, b));
    }

    vector<bool> used(n);					//использованные вершины
    vector<int> mind(n, INF), p(n, -1);		//расстояния и предки
    mind[0] = 0;

    forn(i, n) {
        int v = -1;											//устанавливаем новую свободную
        forn(j, n) {										//вершину, от которой будем
            if(!used[j] && (v == -1 || mind[j] < mind[v]))	//искать кратчайшее ребро
				v = j;
        }

        used[v] = true;
        if(p[v] != -1 && edge.find(make_pair(min(v, p[v]), max(v, p[v]))) == edge.end())	//если ребра нет в сете
			cout << v + 1 << ' ' << p[v] + 1 << endl;										//готовых рёбрышек, то выводим

        forn(j, n) {
            if(!used[j] && j != v) {											//если вершина непоюзана и не является
                pair<int, int> a = cor[v];										//той, от которой начинаем поиск, то
                int len = leng(a, cor[j]);										//вычисляем расстояние между точками
                if(edge.find(make_pair(min(v, j), max(v, j))) != edge.end())	//с координатами от точки поиска cor[v]
                    len = 0;													//до текущей cor[j]. И если ребро есть
                if(len < mind[j]) {												//в сете готовых ребрышек, то обнуляем
					mind[j] = len;												//расстояние и затем ставим минимальное
                    p[j] = v;													//ребро из текущего и начального
                }
            }
        }
    }
    return 0;
}
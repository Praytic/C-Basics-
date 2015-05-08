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
 
int leng(const pair<int, int> &a, const pair<int, int> &b) {	// ������� ������������ ����������
    return (a.first - b.first) * (a.first - b.first) +			// �� ���� ����� � ���������� ���
		   (a.second - b.second) * (a.second - b.second);		// �������.
}
 
int main() {
    int n, m;
    cin >> n;
    vector<pair<int, int>> cor(n);		//������ ���� ������
    forn(i, n)
        cin >> cor[i].first >> cor[i].second;
    cin >> m;
    set<pair<int, int>> edge;			//��� ������� �������
    forn(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if(a > b)
            swap(a, b);
        edge.insert(make_pair(a, b));
    }

    vector<bool> used(n);					//�������������� �������
    vector<int> mind(n, INF), p(n, -1);		//���������� � ������
    mind[0] = 0;

    forn(i, n) {
        int v = -1;											//������������� ����� ���������
        forn(j, n) {										//�������, �� ������� �����
            if(!used[j] && (v == -1 || mind[j] < mind[v]))	//������ ���������� �����
				v = j;
        }

        used[v] = true;
        if(p[v] != -1 && edge.find(make_pair(min(v, p[v]), max(v, p[v]))) == edge.end())	//���� ����� ��� � ����
			cout << v + 1 << ' ' << p[v] + 1 << endl;										//������� �������, �� �������

        forn(j, n) {
            if(!used[j] && j != v) {											//���� ������� ��������� � �� ��������
                pair<int, int> a = cor[v];										//���, �� ������� �������� �����, ��
                int len = leng(a, cor[j]);										//��������� ���������� ����� �������
                if(edge.find(make_pair(min(v, j), max(v, j))) != edge.end())	//� ������������ �� ����� ������ cor[v]
                    len = 0;													//�� ������� cor[j]. � ���� ����� ����
                if(len < mind[j]) {												//� ���� ������� ��������, �� ��������
					mind[j] = len;												//���������� � ����� ������ �����������
                    p[j] = v;													//����� �� �������� � ����������
                }
            }
        }
    }
    return 0;
}
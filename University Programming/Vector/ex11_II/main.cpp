#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x;
    cout << ">number of elements: ";
    cin >> n;
    cout << ">enter x: ";
    cin >> x;
    cout << ">enter inserting element: ";
    cin >> c;
    cout << ">elements: ";
    vector<int> a(n);
    for (int i = 0; i < a.size(); i++) {
        cin >> a[i];
        if (a[i] % 10 == x) {
            a.insert(a.begin() + i, c);
            i++;
        }
    }
    cout << ">result: ";
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << ' ';
    }

    return 0;
}


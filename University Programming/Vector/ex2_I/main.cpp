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
    cout << ">elements: ";
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 2 == 0)
            a[i] = x;
    }
    cout << ">result: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }

    return 0;
}


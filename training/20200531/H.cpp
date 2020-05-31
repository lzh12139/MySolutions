#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[10];
    for (int i = 1; i <= 6; i++)
        cin >> a[i];
    cout << max(0, a[4] - a[1]) + max(0, a[5] - a[2]) + max(0, a[6] - a[3]) << endl;
}
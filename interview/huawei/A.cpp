#include <bits/stdc++.h>
using namespace std;

int C(int n, int m)
{
    int res = 1;
    for (int i = m, j = n; j >= 1; j--, i--)
        res = res * i;
    for (int i = 1; i <= n; i++)
        res = res / i;
    return res;
}

int num[30];
int main()
{
    string s = "";
    while (cin >> s)
        ;
    int n = s.size();
    if (n == 0) {
        cout << "0\n";
        return 0;
    }
    int ans = 1;
    for (auto i : s)
        num[i - 'a' + 1]++;
    for (int i = 1; i <= 26; i++)
        if (num[i])
            ans = ans * C(num[i], n), n -= num[i];
    cout << ans << "\n";
}
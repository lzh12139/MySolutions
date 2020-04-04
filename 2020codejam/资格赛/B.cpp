#include <bits/stdc++.h>
using namespace std;

char s[110];
int main()
{
    int t;
    cin >> t;
    for (int kase = 1; kase <= t; kase++) {
        cin >> s + 1;
        int n = strlen(s + 1);
        s[0] = '0';
        cout << "Case #" << kase << ": ";
        for (int i = 1; i <= n; i++) {
            int tmp = s[i] - s[i - 1];
            while (tmp > 0)
                cout << "(", tmp--;
            while (tmp < 0)
                cout << ")", tmp++;
            cout << s[i];
        }
        for (int i = 1; i <= s[n] - '0'; i++)
            cout << ")";
        cout << endl;
    }
}
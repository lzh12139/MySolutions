#include <bits/stdc++.h>
using namespace std;

#define judge(x) (x == 'a' || x == 'i' || x == 'e' || x == 'o' || x == 'u')
char s[100010];
int main()
{
    cin >> s + 1;
    int n = strlen(s + 1);
    vector<int> v;
    for (int i = 1; i <= n; i++)
        if (judge(s[i]))
            v.push_back(i);
    if (v.size() == 0)
        cout << 1 << endl;
    else if (!judge(s[1]))
        cout << 0 << endl;
    else if (v.size() == 1 && judge(s[1]))
        cout << n << endl;
    else {
        int x = v.size() - 1 >> 1;
        cout << v[x + 1] - v[x] << endl;
    }
}
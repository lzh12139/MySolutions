#include <bits/stdc++.h>
using namespace std;
unordered_map<int, int> m;
int solve(int n)
{
    if (m[n])
        return m[n];
    int ans = n;
    for (int i = 2; 1ll * i * i <= n; i++)
        if (n % i == 0) {
            ans = min(ans, solve(i) + solve(n / i) - 1);
        }
    return m[n] = ans;
}
int main()
{
    m[1] = 1, m[2] = 2, m[3] = m[4] = 3;
    int t;
    cin >> t;
    while (t--) {
        int n, ans;
        cin >> n;
        cout << solve(n) << endl;
    }
}
/*
1 1
2 2
3 3
4 3
5 5
6 4
7 7
8 4
9 5
10 6
11 11
12 5
13 13
14 8
15 7
16 5
17 17
18 6
19 19
20 7
*/
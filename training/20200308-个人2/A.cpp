#include <bits/stdc++.h>
using namespace std;
char s[100010], t[100010];
int main()
{
    int n;
    scanf("%d%s%s", &n, s + 1, t + 1);
    for (int i = 2; i <= n; i++)
        if (s[i] > t[i]) {
            printf("YES\n1 %d\n", i);
            return 0;
        }
    if (n == 2) {
        if (s[2] > t[2] || (s[2] == t[2] && s[1] > t[1]))
            printf("YES\n1 2\n");
        else
            printf("NO\n");
        return 0;
    }
    if (s[1] > t[1]) {
        printf("YES\n%d %d\n", n - 1, n);
        return 0;
    }

    printf("NO\n");
}
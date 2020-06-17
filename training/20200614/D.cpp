#include <bits/stdc++.h>
using namespace std;

char ans[210][210];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m, inv = 0;
        scanf("%d%d", &n, &m);
        if (n % 2 && m % 2) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    printf("(");
                printf("\n");
            }
            continue;
        }
        if (n % 2 || m % 2) {
            if (m % 2)
                swap(n, m), inv = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m / 2; j++)
                    ans[i][j] = '(';
                for (int j = 1 + m / 2; j <= m; j++)
                    ans[i][j] = ')';
            }
        } else if (n < 6 || m < 6) {
            if (n < m)
                swap(n, m), inv = 1;
            for (int i = 1; i <= n / 2; i++)
                for (int j = 1; j <= m; j += 2)
                    ans[i][j] = '(', ans[i][j + 1] = ')';
            for (int i = n / 2 + 1; i <= n; i++) {
                for (int j = 3; j <= m; j += 2)
                    ans[i][j] = ')';
                for (int j = 2; j <= m; j += 2)
                    ans[i][j] = '(';
                ans[i][1] = '(', ans[i][m] = ')';
            }
        } else {
            for (int i = 1; i <= m; i++)
                ans[1][i] = '(', ans[n][i] = ')';
            for (int i = 2; i < n; i++)
                ans[i][1] = '(', ans[i][m] = ')';
            for (int i = 2; i < n; i+=2) {
                for (int j = 1; j <= m; j += 2)
                    ans[i][j] = '(', ans[i][j + 1] = ')';
                for (int j = 2; j < m; j += 2)
                    ans[i + 1][j] = '(', ans[i + 1][j + 1] = ')';
            }
        }

        if (!inv)
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++)
                    printf("%c", ans[i][j]);
                printf("\n");
            }
        else
            for (int j = 1; j <= m; j++) {
                for (int i = 1; i <= n; i++)
                    printf("%c", ans[i][j]);
                printf("\n");
            }
    }
}
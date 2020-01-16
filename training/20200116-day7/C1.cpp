#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

//vector<int> a[100010], b[100010];
char s[100010];
int a[6][6], b[6][6];
int main()
{
    freopen("in.txt", "w", stdout);
    for (int jjj = 0; jjj < (1 << 16); jjj++) {
        int tmp = jjj, x = 1, y = 1;
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        while (tmp) {
            if (tmp & 1)
                b[x][y] = a[x][y] = 1;
            y++;
            if (y == 5)
                x++, y = 1;
            tmp >>= 1;
        }
        int ans = 0, k = 4;
        while (1) {
            for (int i = 1; i <= k; i++)
                for (int j = 1; j <= k; j++)
                    a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            for (int i = 1; i <= k; i++)
                for (int j = 1; j <= k; j++) {
                    a[i][j] %= 2;
                }
            ans++;
            for (int i = 1; i <= k; i++)
                for (int j = 1; j <= k; j++)
                    if (a[i][j] != b[i][j])
                        goto over;
            goto gg;
        over:;
        }
    gg:
        if (ans != 4) {
            for (int i = 1; i <= 4; i++)
                for (int j = 1; j <= 4; j++)
                    printf("%d%c", b[i][j], " \n"[j == 4]);
            printf("%d %d\n", jjj, ans);
        }
    }
    /*int n, m;
    scanf("%d%d", &n, &m);
    a[0].resize(m + 1);
    b[0].resize(m + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        a[i].resize(m + 1);
        b[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j] - '0';
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];*/
}
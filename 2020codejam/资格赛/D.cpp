#include <bits/stdc++.h>
using namespace std;
#define rev(x) (n - x + 1)
int a[20][200], qu[200];
int Q(int x)
{
    printf("%d\n", x);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}
int main()
{
    int t, n;
    scanf("%d%d", &t, &n);
    for (int i = 1; i <= n / 2; i++)
        qu[2 * i - 1] = i, qu[2 * i] = n - i + 1;

    while (t--) {
        memset(a, -1, sizeof(a));
        int cur = 1, top = 0, sta[5], vis[5] = { 0 };

        int T;
        for (T = 1; T <= 150; T++) {
            int st = T / 10, m = T % 10;
            if (m == 0)
                st--;
            if (1 <= m && m <= top) {
                int x = Q(sta[m]);
                int y = (a[st - 1][sta[m]] + a[st - 1][rev(sta[m])]) % 2;
                int flag = (x != a[st - 1][sta[m]] ? 1 : 0);
                for (int i = 1; i <= n / 2; i++)
                    if (a[st - 1][i] >= 0 && a[st - 1][rev(i)] >= 0) {
                        if ((a[st - 1][i] + a[st - 1][rev(i)]) % 2 == y) {
                            a[st][i] = a[st - 1][i] ^ flag;
                            a[st][rev(i)] = a[st - 1][rev(i)] ^ flag;
                        }
                    }
            } else if (cur <= n) {
                int x = qu[cur++];
                a[st][x] = Q(x);
                //cout << "******   " << x << " " << a[st][x] << endl;
                if (a[st][rev(x)] != -1) {
                    int y = (a[st][rev(x)] + a[st][x]) % 2;
                    if (!vis[y])
                        sta[++top] = x, vis[y]++;
                }
            } else {
                int findd = 0;
                for (int i = 1; i <= n; i++) {
                    if (a[st][i] == -1) {
                        a[st][i] = Q(i);

                        if (a[st][rev(i)] != -1) {
                            int y = (a[st][rev(i)] + a[st][i]) % 2;
                            if (!vis[y])
                                sta[++top] = i, vis[y]++;
                        }

                        findd++;
                        break;
                    }
                }
            }
        }

        T = (T - 1) / 10;
        for (int i = 1; i <= n; i++) {
            assert(a[T][i] != -1);
            if (a[T][i])
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        fflush(stdout);

        char ans[10];
        scanf("%s", ans + 1);
        //assert(ans[1] == 'Y');
        if (ans[1] == 'N')
            return 0;
    }
}
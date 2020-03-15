#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

const int N = 1e6;
int a[N + 10], b[N + 10];
int main()
{
    int n, m, maxx = -1, minn = 1e9 + 5;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxx = max(maxx, a[i]), minn = min(minn, a[i]);
        if (a[i] != maxx && a[i] != minn) {
            printf("-1");
            return 0;
        }
    }
    if (maxx == minn) {
        printf("1\n");
        return 0;
    }
    int ans = 0, cnt = 0;
    b[++cnt] = a[1];
    for (int i = 2; i <= n; i++)
        if (a[i] != b[cnt])
            b[++cnt] = a[i];
    for (int i = 1; i <= cnt; i++)
        if (b[i] == minn)
            ans++;
    printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int q[N];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, l = 0, r = -1;
        scanf("%d", &n);
        char s[10];
        for (int i = 1; i <= n; i++) {
            scanf("%s", s + 1);
            if (s[1] == 'P' && s[2] == 'U') { // push
                int tmp;
                scanf("%d", &tmp);
                q[++r] = tmp;
            } else if (s[1] == 'P' && s[2] == 'O') { // pop
                if (l > r)
                    printf("-1\n");
                else
                    l++;
            } else if (s[1] == 'T') { // top
                if (l > r)
                    printf("-1\n");
                else
                    printf("%d\n", q[l]);
            } else if (s[1] == 'S') { // size
                printf("%d\n", r - l + 1);
            } else {
                l = 0;
                r = -1;
            }
        }
    }
}
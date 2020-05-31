#include <bits/stdc++.h>
using namespace std;

char s[110];
int main()
{
    const int dayst = 9 * 60 * 60 + 30 * 60;
    const int timeup = 8 * 60 * 60 + 30 * 60;
    const int daylen = 8 * 60 * 60;
    const int evest = 12 * 60 * 60 + 30 * 60;
    const int evelen = 9 * 60 * 60;
    int n;
    while (~scanf("%d", &n) && n) {
        int ans = 0;
        while (n--) {
            scanf("%s", s + 1);
            int len = strlen(s + 1), day = 0;
            s[++len] = ':';
            if (s[1] == 'D')
                day = 1;
            int st = -1, end = -1;
            for (int i = 3, tmp = 0, maohao = 0; i <= len; i++) {
                if (s[i] == ':') {
                    maohao++;
                    if (maohao == 3) {
                        tmp = tmp / 10000 * 3600 + tmp / 100 % 100 * 60 + tmp % 100;
                        if (st == -1)
                            st = tmp;
                        else
                            end = tmp;
                        maohao = tmp = 0;
                    }
                } else
                    tmp = tmp * 10 + s[i] - '0';
            }

            st = max(st, timeup);

            if (day == 1) {
                if (st > dayst || daylen > end - st)
                    ans++;
            } else {
                if (st > evest || evelen > end - st)
                    ans++;
            }
        }
        if (ans == 0)
            printf("All OK\n");
        else if (ans == 1)
            printf("1 Point(s) Deducted\n");
        else if (ans == 2)
            printf("2 Point(s) Deducted\n");
        else if (ans == 3)
            printf("3 Point(s) Deducted\n");
        else
            printf("Issue Show Cause Letter\n");
    }
}
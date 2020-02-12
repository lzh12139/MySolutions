#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

ll w[15][20], p[20];
int main()
{
    for (int i = 1; i <= 9; i++)
        w[i][2] = pow(i, 2);
    p[2] = 100;
    for (int i = 3; i <= 17; i++) {
        p[i] = p[i - 1] * 10;
        for (int j = 1; j <= 9; j++)
            w[j][i] = w[j][i - 1] * j;
    }
    int cnt = 3;
    for (ll i = 100;; i++) {
        for (int j = 3; j <= 18; j++)
            if (p[j] >= i) {
                if (p[j] == i)
                    cnt++, printf("----%lld\n", i);
                break;
            }
        ll tmp = i, sum = 0;
        while (tmp) {
            sum += w[tmp % 10][cnt];
            tmp /= 10;
        }
        if (sum == i)
            printf("%lld\n", i);
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    scanf("%d", &q);
    while (q--) {
        long long x;
        int k;
        scanf("%lld%d", &x, &k);
        long long tmp = x, dep = 0;
        while (tmp) {
            tmp >>= 1;
            dep++;
        }
        if (dep <= k)
            printf("-1\n");
        else {
            k = dep - k;
            while (k-- && x) {
                x >>= 1;
            }
            printf("%lld\n", x);
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int checkStart(int x, int k)
{
    x %= k;
    return x % 2 == 0 ? 1 : 0;
}
int main()
{
    int n, k;
    //scanf("%d%d", &n, &k);
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= i; j++) {
            n = i, k = j;
            printf("%d %d\n",n,k);
            int maxx = max((n + k - 1) / k, 2);
            for (int i = 0; i < n; ++i) {
                printf("%d ", (checkStart(i, k) + i / k) % maxx + 1);
            }
            printf("\n\n");
        }
}
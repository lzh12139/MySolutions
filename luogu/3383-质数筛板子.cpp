#include <bits/stdc++.h>
using namespace std;
const int N = 1e8;
int prime[N + 10], isprime[N + 10];
void pre()
{
    for (int i = 2; i <= N; i++) {
        if (!isprime[i])
            prime[++prime[0]] = i;
        int inf = N / i;
        for (int j = 1; j <= prime[0] && prime[j] <= inf; j++) {
            isprime[i * prime[j]]++;
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main()
{
    pre();
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", prime[x]);
    }
}
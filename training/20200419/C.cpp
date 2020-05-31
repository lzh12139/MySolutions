#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

const int N = 1e6;
const int mod = 1e7 + 7;
int a[N + 10], fac[N + 10];

int prime[N + 10];
void init()
{
    for (int i = 2; i <= N; i++) {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= N / i; j++) {
            prime[prime[j] * i]++;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    init();
    int n;
    while (cin >> n && n) {
        int cnt = 1;
        long long ans = 1;

        for (int i = 1; i <= prime[0] && prime[i] <= n; i++) {
            int tmp = n, cnt = 0;
            while (tmp >= prime[i])
                tmp /= prime[i], cnt += tmp;
            ans = ans * (tmp + 1) * (tmp + 2) / 2 % mod;
        }
        cout << ans << "\n";
    }
}
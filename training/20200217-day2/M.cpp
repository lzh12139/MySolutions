#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

vector<pii> v[15];
int main()
{
    int n;
    scanf("%d", &n);
    int add = 64, j = 1;
    if (add > n) {
        printf("1\n1\n1 %d\n", n);
        return 0;
    }
    while (add <= n) {
        int cur = 1;
        while (1) {
            v[j].push_back({ cur, min(n, cur - 1 + add) });
            cur += add;
            if (cur > n)
                break;
        }
        add = add * 4;
        j++;
    }
    v[j].push_back({ 1, n });
    printf("%d\n", j);
    for (int i = 1; i <= j; i++) {
        printf("%d\n", v[i].size());
        for (auto p : v[i])
            printf("%d %d\n", p.ff, p.ss);
    }
}
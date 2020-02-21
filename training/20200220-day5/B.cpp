#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

vector<int> v[400010];
int a[400010], deg[400010];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int j;
        scanf("%d%d", &a[i], &j);
        while (j--) {
            int x;
            scanf("%d", &x);
            v[i].push_back(x);
            deg[x]++;
        }
    }
    int ans = 0, last = n - 1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= n; i++)
        if (!deg[i])
            pq.push({ a[i], i });
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        ans = max(ans, last + x.ff);
        last--;
        for (auto i : v[x.ss]) {
            deg[i]--;
            if (!deg[i])
                pq.push({ a[i], i });
        }
    }
    printf("%d\n", ans);
}
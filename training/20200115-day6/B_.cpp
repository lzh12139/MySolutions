#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

const int N = 2e5 + 10;
int a[N], num[N], vis[N];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), num[a[i]]++;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int last = 0;
    for (int i = 1; i <= n; i++) {
        pq.push(mp(a[i], i));
        if (num[a[i]] == 1) {
            while (!pq.empty() && !vis[a[i]]) {
                pii x = pq.top();
                pq.pop();
                if (x.ss > last && !vis[x.ff]) {
                    vis[x.ff]++;
                    last = x.ss;
                    printf("%d ", x.ff);
                }
            }
        }
        num[a[i]]--;
    }
}
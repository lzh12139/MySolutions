#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

const int N = 1e5;
int a[N];
int main()
{
    using p = pair<int, pii>;
    priority_queue<p> pq;
    for (int i = 1; i <= 10; i++)
        for (int j = i + 1; j <= 10; j++)
            pq.push({ i * j, { i, j } });
    while (!pq.empty()) {
        cout << pq.top().ff << " " << pq.top().ss.ff << " " << pq.top().ss.ss << "\n";
        pq.pop();
    }
}
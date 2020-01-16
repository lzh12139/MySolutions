#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

vector<int> a[100010], b[100010];
char s[100010];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    a[0].resize(m + 1);
    b[0].resize(m + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        a[i].resize(m + 1);
        b[i].resize(m + 1);
        for (int j = 1; j <= m; j++)
            a[i][j] = s[j] - '0';
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];

    
}
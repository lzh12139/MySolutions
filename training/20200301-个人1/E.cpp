#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char a[200010], b[200010];
int main()
{
    IOS;
    cin >> a + 1 >> b + 1;
    int n = strlen(a + 1), l = -1, r = -1;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i]) {
            l = i;
            break;
        }
    for (int i = n; i >= 1; i--)
        if (a[i] != b[i]) {
            r = i;
            break;
        }
    if (l == -1)
        cout << "YES\n";
    else {
        int gg = 0;
        for (int i = l, j = r; i <= r; i++, j--)
            if (a[i] != b[j]) {
                gg++;
                break;
            }
        if (gg)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
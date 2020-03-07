#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char s[200010];
vector<char> l, r;
int main()
{
    int q, rev = 0, n;
    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);
    while (q--) {
        int op, x;
        scanf("%d", &op);
        char tmp[5];
        if (op == 1)
            rev ^= 1;
        else {
            scanf("%d%s", &x, tmp + 1);
            if (x == 1) {
                if (rev)
                    r.push_back(tmp[1]);
                else
                    l.push_back(tmp[1]);
            } else {
                if (rev)
                    l.push_back(tmp[1]);
                else
                    r.push_back(tmp[1]);
            }
        }
    }
    reverse(l.begin(), l.end());
    if (rev) {
        reverse(s + 1, s + 1 + n);
        reverse(l.begin(), l.end());
        reverse(r.begin(), r.end());
        for (auto i : r)
            printf("%c", i);
        printf("%s", s + 1);
        for (auto i : l)
            printf("%c", i);
    } else {
        for (auto i : l)
            printf("%c", i);
        printf("%s", s + 1);
        for (auto i : r)
            printf("%c", i);
    }
}

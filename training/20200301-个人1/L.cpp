#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

int p[30][200010];
char s[200010];
int ans[200010], cur[200010];
int main()
{
    //IOS;
    int q;
    cin >> s + 1 >> q;
    int n = strlen(s + 1);
    for (int i = 1; i <= n; i++) {
        int c = s[i] - 'a';
        p[c][++p[c][0]] = i;
    }
    int top = 0;
    ans[0] = 1;
    while (q--) {
        cin >> s + 1;
        if (s[2] == 'u') {
            char op[5];
            cin >> op + 1;
            int c = op[1] - 'a';
            int x = upper_bound(p[c] + 1, p[c] + 1 + p[c][0], cur[top]) - p[c];
            top++;
            if (x > p[c][0])
                cur[top] = n, ans[top] = 0;
            else
                cur[top] = p[c][x], ans[top] = 1;
        } else
            top--;
        cout << (ans[top] ? "YES" : "NO") << endl;
    }
}
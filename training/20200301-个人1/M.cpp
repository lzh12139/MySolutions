#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef long long ll;
typedef vector<int> V;
typedef pair<int, int> pii;

char a[200010], b[200010], c[200010];
int main()
{
    cin >> a + 1 >> b + 1 >> c + 1;
    int n = strlen(a + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i] || a[i] != c[i] || b[i] != c[i]) {
            if (b[i] == c[i])
                ans.push_back(1);
            else if (a[i] == c[i])
                ans.push_back(2);
            else if (a[i] == b[i])
                ans.push_back(3);
            else
                ans.push_back(4);
        }
    if (ans.size() <= 1)
        cout << "Ambiguous";
    else if (ans.size() == 2) {
        if (ans[0] == 4 && ans[1] == 4)
            cout << "Impossible";
        else if (ans[0] == 4 || ans[1] == 4) {
            int ano = ans[0];
            if (ano == 4)
                ano = ans[1];
            for (int i = 1, j = 0; i <= n; i++)
                if (a[i] == b[i] && a[i] == c[i])
                    cout << a[i];
                else {
                    if (ans[j] == 4) {
                        if (ano == 1)
                            cout << a[i];
                        else if (ano == 2)
                            cout << b[i];
                        else
                            cout << c[i];
                    } else {
                        if (ano == 1)
                            cout << b[i];
                        else
                            cout << a[i];
                    }
                    j++;
                }
        } else {
            if (ans[0] == ans[1])
                cout << "Ambiguous";
            else {
                int ano = 6 - ans[0] - ans[1];
                for (int i = 1, j = 0; i <= n; i++)
                    if (a[i] == b[i] && a[i] == c[i])
                        cout << a[i];
                    else {
                        if (ano == 1)
                            cout << a[i];
                        else if (ano == 2)
                            cout << b[i];
                        else
                            cout << c[i];
                    }
            }
        }
    } else if (ans.size() == 3) {
        for (auto i : ans)
            if (i == 4) {
                cout << "Impossible";
                return 0;
            }
        if (ans[0] == ans[1] || ans[0] == ans[2] || ans[1] == ans[2]) {
            cout << "Impossible";
            return 0;
        }
        for (int i = 1, j = 0; i <= n; i++)
            if (a[i] == b[i] && a[i] == c[i])
                cout << a[i];
            else {
                if (ans[j] == 1)
                    cout << b[i];
                else
                    cout << a[i];
                j++;
            }
    } else
        cout << "Impossible";
}
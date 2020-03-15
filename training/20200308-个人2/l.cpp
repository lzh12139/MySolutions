#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ff first
#define ss second

pii a[1010], b[1010];
pii ma[1010], mb[1010];
map<string, int> mpa;
const string s1 = "define", s2 = "print", s3 = "read";

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s, t;
        cin >> s;
        if (s.size() == 4 && s == s3) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            a[i] = (pii){ 3, mpa[t] };
        } else if (s.size() == 5 && s == s2) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            a[i] = (pii){ 2, mpa[t] };
        } else if (s.size() == 6 && s == s1) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            a[i] = (pii){ 1, mpa[t] };
        } else {
            int tmp1 = 0, tmp2 = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '=')
                    tmp1 = i;
                else if (s[i] == '+')
                    tmp2 = i;
            string aa = s.substr(0, tmp1),
                   bb = s.substr(tmp1 + 1, tmp2 - tmp1 - 1),
                   cc = s.substr(tmp2 + 1, s.size() - tmp2 - 1);
            if (!mpa[aa])
                mpa[aa] = ++cnt;
            if (!mpa[bb])
                mpa[bb] = ++cnt;
            if (!mpa[cc])
                mpa[cc] = ++cnt;
            a[i] = (pii){ 4, mpa[aa] };
            ma[i] = (pii){ mpa[bb], mpa[cc] };
        }
    }
    int m;
    cnt = 0, mpa.clear();
    cin >> m;
    for (int i = 1; i <= m; i++) {
        string s, t;
        cin >> s;
        if (s.size() == 4 && s == s3) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            b[i] = (pii){ 3, mpa[t] };
        } else if (s.size() == 5 && s == s2) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            b[i] = (pii){ 2, mpa[t] };
        } else if (s.size() == 6 && s == s1) {
            cin >> t;
            if (!mpa[t])
                mpa[t] = ++cnt;
            b[i] = (pii){ 1, mpa[t] };
        } else {
            int tmp1 = 0, tmp2 = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '=')
                    tmp1 = i;
                else if (s[i] == '+')
                    tmp2 = i;
            string aa = s.substr(0, tmp1),
                   bb = s.substr(tmp1 + 1, tmp2 - tmp1 - 1),
                   cc = s.substr(tmp2 + 1, s.size() - tmp2 - 1);
            if (!mpa[aa])
                mpa[aa] = ++cnt;
            if (!mpa[bb])
                mpa[bb] = ++cnt;
            if (!mpa[cc])
                mpa[cc] = ++cnt;
            b[i] = (pii){ 4, mpa[aa] };
            mb[i] = (pii){ mpa[bb], mpa[cc] };
        }
    }
    if (n == m) {
        for (int i = 1; i <= n; i++) {
            if (a[i].ff != b[i].ff || a[i].ss != b[i].ss) {
                printf("NO\n");
                return 0;
            }
            if (a[i].ff == 4 && (ma[i].ff != mb[i].ff || ma[i].ss != mb[i].ss)) {
                printf("NO\n");
                return 0;
            }
        }
        printf("YES\n");
    } else
        printf("NO\n");
}
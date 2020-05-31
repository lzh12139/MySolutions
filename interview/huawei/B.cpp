#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ans = "";
    int k;
    vector<int> v[26];
    cin >> s >> k;
    int n = s.size();
    k = n - k;
    for (int i = 0; i < n; i++)
        v[s[i] - 'a'].push_back(i);
    int last = -1;
    for (int i = 1; i <= k; i++) {
        int ok = 0;
        for (int j = 0; j < 26; j++)
            if (!v[j].empty()) {
                auto x = upper_bound(v[j].begin(), v[j].end(), last);
                if (x != v[j].end() && (n - *x - 1 + i) >= k) {
                    ans += char(j + 'a');
                    last = *x;
                    //cout<<j<<" "<<*x<<endl;
                    ok = 1;
                    break;
                }
            }
        if (ok == 0)
            ans += s[++last];
    }
    cout << ans << endl;
}
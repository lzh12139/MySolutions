#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long

string str[100010];
pair<ll, ll> pii[100010];
int main()
{
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> str[i] >> pii[i].ff;
        pii[i].ss = i;
    }
    sort(pii + 1, pii + 1 + n);
    for (int i = 1; i < n; i++) {
        ll s = pii[i].ff * i;
        cout << str[pii[i].ss] << " " << s / m << " " << m - s % m << "\n";
    }
    cout << str[pii[n].ss] << "\n";
}
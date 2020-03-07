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
char s[10];
int main()
{
    cin >> s + 1;
    int a = 0, b = 0;
    for (int i = 1; i <= 3; i++)
        if (s[i] == 'A')
            a++;
        else if (s[i] == 'B')
            b++;
    cout << (a && b ? "Yes" : "No");
}
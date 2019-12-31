/**
 * Author: hrynb
 * Time: 2019-08-31 00:58:17
**/

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) emplace_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%ll%c", a, b)
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define _yes printf("YES\n")
#define _no printf("NO\n")

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> V;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef map<string, int> msi;

int a[10];
int main()
{
    int n;
    scanf("%d", &n);
    char s1[5], s2[5];
    scanf("%s%s", s1 + 1, s2 + 1);
    _yes;
    for (int i = 1; i <= 3; i++)
        a[i] = i;
    if (s1[1] != s1[2] && s2[1] != s2[2])
    {
        do
        {
            int gg = 0;
            for (int i = 1; i <= 2; i++)
                if (a[i] == s1[1] - 'a' + 1 && a[i + 1] == s1[2] - 'a' + 1)
                    gg++;
            for (int i = 1; i <= 2; i++)
                if (a[i] == s2[1] - 'a' + 1 && a[i + 1] == s2[2] - 'a' + 1)
                    gg++;

            if (!gg)
            {
                for (int o = 1; o <= 3; o++)
                    for (int i = 1; i <= n; i++)
                        printf("%c", a[o] + 'a' - 1);
                break;
            }
        } while (next_permutation(a + 1, a + 1 + 3));
    }
    else
    {
        do
        {
            int gg = 0;
            for (int i = 1; i <= 2; i++)
                if (a[i] == s1[1] - 'a' + 1 && a[i + 1] == s1[2] - 'a' + 1)
                    gg++;
            if (n > 1 && a[3] == s1[1] - 'a' + 1 && a[1] == s1[2] - 'a' + 1)
                gg++;
            for (int i = 1; i <= 2; i++)
                if (a[i] == s2[1] - 'a' + 1 && a[i + 1] == s2[2] - 'a' + 1)
                    gg++;
            if (n > 1 && a[3] == s2[1] - 'a' + 1 && a[1] == s2[2] - 'a' + 1)
                gg++;

            if (!gg)
            {
                for (int i = 1; i <= n; i++)
                    for (int o = 1; o <= 3; o++)
                        printf("%c", a[o] + 'a' - 1);
                break;
            }
        } while (next_permutation(a + 1, a + 1 + 3));
    }
}
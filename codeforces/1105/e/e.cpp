/**
 * Author: hrynb
 * Time: 2019-08-27 20:47:37
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
#define _yes printf("Yes\n")
#define _no printf("No\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef map<string, int> msi;

msi m;
int can[100010], w[50][50], ans = 0, mm, sel[50], deg[50];
set<int> se[50];
ll e[50], base;
map<ll, int> f;

int dfs(ll x)
{
	//printf("%lld\n", x);
	if (f.find(x) != f.end())
		return f[x];
	int t = 0;
	ll cmp = x;
	while (cmp)
		cmp >>= 1, t++;
	t--;
	//printf("%d\n", t);
	int a = 0, b = 0;
	a = dfs(x ^ (1ll << t));
	//if (x & e[t] != x)
	b = dfs(x & e[t + 1]);
	return f[x] = max(a, b + 1);
}

int main()
{
	//IOS;
	int n, cnt = 0, c = 1, pp = 0;
	cin >> n >> mm;
	base = (1ll << mm) - 1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == 2)
		{
			string s;
			cin >> s;
			if (!m[s])
				m[s] = ++cnt;
			se[m[s]].insert(c);
			pp = 1;
		}
		else if (pp)
			c++;
	}

	for (int i = 1; i <= mm; i++)
		for (int o = i + 1; o <= mm; o++)
			if (se[i].size() && se[o].size())
			{
				int gg = 0;
				for (auto j : se[i])
					can[j]++;
				for (auto j : se[o])
					if (can[j])
					{
						gg++;
						break;
					}

				if (!gg)
					w[i][o] = w[o][i] = 1;

				for (auto j : se[i])
					can[j] = 0;
			}

	for (int i = 1; i <= mm; i++)
	{
		for (int o = 1; o <= mm; o++)
			if (w[i][o])
				e[i] |= (1ll << o - 1);
		//e[i] ^= base;
		//printf("%lld\n", e[i]);
	}

	f[0] = 0;
	ans = dfs(base);

	cout << ans << endl;
}
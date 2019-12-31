#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb emplace_back

ll quick_mod(ll a, ll b, ll m) {
	ll ans = 1;
	a %= m;
	while(b) {
		if(b & 1) {
			ans = ans * a % m;
			b--;
		}
		b >>= 1;
		a = a * a % m;
	}
	return ans;
}

struct T {
	ll p, d;
};

ll w;

T multi_er(T a, T b, ll m) {
	T ans;
	ans.p = (a.p * b.p % m + a.d * b.d % m * w % m) % m;
	ans.d = (a.p * b.d % m + a.d * b.p % m) % m;
	return ans;
}

T power(T a, ll b, ll m) {
	T ans;
	ans.p = 1;
	ans.d = 0;
	while(b) {
		if(b & 1) {
			ans = multi_er(ans, a, m);
			b--;
		}
		b >>= 1;
		a = multi_er(a, a, m);
	}
	return ans;
}

ll Legendre(ll a, ll p) {
	return quick_mod(a, (p-1)>>1, p);
}

ll mod(ll a, ll m) {
	a %= m;
	if(a < 0) a += m;
	return a;
}

ll Solve(ll n,ll p) {
	if(p == 2) return 1;
	if (Legendre(n, p) + 1 == p)
		return -1;
	ll a = -1, t,cnt=1;
	while(cnt++<=100000) {
		a = rand() % p;
		t = a * a - n;
		w = mod(t, p);
		if(Legendre(w, p) + 1 == p) break;
	}
	T tmp;
	tmp.p = a;
	tmp.d = 1;
	T ans = power(tmp, (p + 1)>>1, p);
	return ans.p;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		ll b,c;
		scanf("%lld%lld",&b,&c);
		ll mod=1e9+7;
		if(b%2==0) {
			if(b*b/4%mod==c) {
				printf("%lld %lld\n",b/2,b/2);
				continue;
			}
		}

		ll a = Solve((b*b%mod-4*c+4*mod)%mod,mod);
		if(a == -1) {
			printf("-1 -1\n");
			continue;
		}
		if((a+b)%2==0) {
			ll ans1=(a+b)/2,ans2=((b-a)/2+mod)%mod;
			if(ans1>ans2)swap(ans1,ans2);
			printf("%lld %lld\n",ans1,ans2);
			continue;
		}
		a=mod-a;
		if((a+b)%2==0) {
			ll ans1=(a+b)/2,ans2=((b-a)/2+mod)%mod;
			if(ans1>ans2)swap(ans1,ans2);
			printf("%lld %lld\n",ans1,ans2);
			continue;
		}
		printf("-1 -1\n");
	}
}

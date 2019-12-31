#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef complex<db> C;
const int N = 1e5 + 5;
const ll mod = 100003;
const db pi = acos(-1);

int n, Q;
ll A, a[N];
vector<ll>w[N << 2];
ll fac[N], rev[N], ans[N];

ll qpow(ll a, ll b) {
	ll r = 1;
	while (b) {
		if (b & 1)r = r * a % mod;
		b >>= 1; a = a * a % mod;
	}
	return r;
}

void preC() {
	fac[0] = 1;
	for (int i = 1; i <= n; ++i)fac[i] = fac[i - 1] * i % mod;
	rev[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; --i)rev[i] = rev[i + 1] * (i + 1) % mod;
}

struct FFT {
	int n, m, rev[N << 2];
	C a[N << 2], b[N << 2];
	void init(int len) {
		for (n = 1, m = 0; n <= len; n <<= 1, m++);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << (m - 1);
			a[i] = C(0, 0);
			b[i] = C(0, 0);
		}
	}
	void fft(C *a, int f) {
		for (int i = 0; i < n; ++i)if (i < rev[i])swap(a[i], a[rev[i]]);
		for (int i = 1; i < n; i <<= 1) {
			db alpha = pi / i;
			if (f == -1)alpha = -pi / i;
			for (int k = 0; k < i; ++k) {
				C w = exp(C(0, alpha * k));
				for (int j = k; j < n; j += (i << 1)) {
					C x = w * a[j + i];
					a[j + i] = a[j] - x;
					a[j] += x;
				}
			}
		}
		return;
	}
	void Calculate() {
		fft(a, 1); fft(b, 1);
		for (int i = 0; i < n; ++i)a[i] *= b[i];
		fft(a, -1);
	}
} F;

void Solve(int x, int l, int r) {
	if (l == r) {
		w[x].push_back(1);
		w[x].push_back(a[l]);
		return;
	}
	int mid = (l + r ) >> 1;
	Solve(x << 1, l, mid);
	Solve(x << 1 | 1, mid + 1, r);
	F.init(r - l + 1);
	for (int i = 0; i <= mid - l + 1; ++i)F.a[i] = C(w[x << 1][i], 0);
	for (int i = 0; i <= r - mid; ++i)F.b[i] = C(w[x << 1 | 1][i], 0);
	F.Calculate();
	for (int i = 0; i <= r - l + 1; ++i) {
		ll val = floor(F.a[i].real() / F.n + 0.5);
		w[x].push_back(val % mod);
	}
}

ll Com(int n, int m) {
	return n < m ? 0 : fac[n] * rev[m] % mod * rev[n - m] % mod;
}

int main() {
    freopen("in.txt","r",stdin);
	freopen("out2.txt","w",stdout);
	scanf("%d%lld%d", &n, &A, &Q);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
		a[i] = qpow(A, a[i] % (mod - 1));
	}
	Solve(1, 1, n);
	preC();
	for (int k = 1; k <= n; ++k) {
		ans[k] = (w[1][k] - Com(n, k) + mod) % mod * qpow(A - 1, mod - 2) % mod;
	}
	for (int i = 1, k; i <= Q; ++i) {
		scanf("%d", &k);
		printf("%lld\n", ans[k]);
	}
}
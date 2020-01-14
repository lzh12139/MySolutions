/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */
 
const int maxn = 4100;
struct Point {
    int x, y;
} a[maxn];
int n;
 
double getS(const Point &x, const Point &y, const Point &z) {
    return 0.5 * ((x.x - z.x) * (y.y - z.y) - (y.x - z.x) * (x.y - z.y));
}
 
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &a[i].x, &a[i].y);
        double ans = 0, max1 = 0, max2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                max1 = max2 = 0;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) {
                        double S = getS(a[i], a[j], a[k]);
                        if (S < eps)  max1 = max(max1, -S);
                        else max2 = max(max2, S);
                    }
                }
                if (!max1 || !max2) continue;
                ans = max(ans, (max2 + max1));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
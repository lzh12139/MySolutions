#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C[60][60];
ll ansp[60][5];
void init()
{
    C[1][0] = C[1][1] = 1;
    C[2][0] = C[2][2] = 1, C[2][1] = 2;
    C[3][0] = C[3][3] = 1, C[3][1] = C[3][2] = 3;
    for (int i = 4; i <= 55; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    for (int j = 1; j <= 55; j++) {
        for (int o = 1; o <= 3; o++) {
            for (int k = o; k <= j; k += 3)
                ansp[j][o] += C[j][k];
        }
    }
}

int main()
{
    init();
    ll n;
    while (cin >> n) {
        ll ans = 0, num = 0;
        for (int i = 55, fir = 0; i >= 0; i--) {
            if (n & (1ll << i)) {
                if (fir == 0) {
                    fir = i;
                    ans += ansp[i][3];
                } else {
                    if (num % 3 == 0)
                        ans += ansp[i][3] + 1;
                    else
                        ans += ansp[i][3 - num % 3];
                }
                num++;
            }
            //cout << ans << endl;
        }
        if (num % 3 == 0)
            ans++;
        cout << "Day " << n << ": Level = " << ans << "\n";
    }
}
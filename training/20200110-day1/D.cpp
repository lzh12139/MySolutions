#include <bits/stdc++.h>
using namespace std;
double dpa[510][510], dpb[510][510];
int dd[] = { 1, 18, 4, 13, 6, 10, 15, 2, 17, 3, 19, 7, 16, 8, 11, 14, 9, 12, 5, 20, 1, 18 };
int main()
{
    const double pa = 1.0 / 20.0, pb = 1.0 / 3.0;
    for (int i = 0; i <= 500; i++)
        dpa[0][i] = dpb[i][0] = 1;
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++) {
            int k1 = 0, k2 = 0;
            double add[5];
            for (int k = 0; k <= 3; k++)
                add[k] = 0;

            for (int k = 1; k <= 20; k++)
                if (i - dd[k] >= 0)
                    dpa[i][j] += pb * (1 - dpb[i - dd[k]][j]);
                else
                    k1++;

            for (int k = 1; k <= 20; k++) {
                double tmp = 0;
                int k2_ = 0;
                for (int o = k - 1; o <= k + 1; o++)
                    if (j - dd[o] >= 0)
                        tmp += 1 - dpa[i][j - dd[o]];
                    else
                        k2_++;
                add[k2_] = max(add[k2_], tmp);
                k2 = max(k2, k2_);
            }

            if (k1) {
                if (k2) {
                    for (int k = 0; k <= 3; k++)
                        if (add[k] != 0) {
                            double tmpa = 0, tmpb = 0, tmp = 0;
                            tmpb = 20.0 * (k * dpa[i][j] + add[k]) / (60.0 - k * k1);
                            tmpa = dpa[i][j] + k1 * tmpb * pa;

                            for (int o = 0; o <= 3; o++)
                                if (add[o] != 0)
                                    tmp = max(tmp, o * tmpa + add[o]);

                            if (tmp == tmpb) {
                                dpa[i][j] = tmpa;
                                dpb[i][j] = tmpb;
                                break;
                            }
                        }
                } else {
                    dpb[i][j] = add[0];
                    dpa[i][j] = k1 * dpb[i][j] + dpa[i][j];
                }
            } else {
                if (k2)
                    for (int k = 0; k <= 3; k++)
                        dpb[i][j] = max(dpb[i][j], pb * (k * pa * dpa[i][j] + add[k]));
                else
                    dpb[i][j] = add[0];
            }
        }
    int n = 1;
    //while (scanf("%d", &n) && n) {
    printf("%.10lf %.10lf\n", dpa[n][n], dpb[n][n]);
    //}
}
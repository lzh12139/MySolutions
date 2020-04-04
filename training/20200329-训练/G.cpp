#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

char a[10], b[10];
const double pi = acos(-1);
const double sq3 = sqrt(3);
int main()
{
    int da, db, la, lb;
    cin >> a + 1 >> da >> la;
    cin >> b + 1 >> db >> lb;

    auto solve = [](char s[], int d, int l) {
        double afa = d;
        if (s[1] == 'C')
            afa += 60;
        if (s[1] == 'D')
            afa += 120;
        afa = afa * pi / 180.0;

        double x = l * cos(afa) + 30, y = l * sin(afa) + 20 * sq3;
        while (x > 2)
            x -= 2.0;
        while (y > 2 * sq3)
            y -= 2.0 * sq3;

        int flag = 0, res = -1;
        if (y > sq3)
            y -= sq3, flag = 1;
        int s1 = 0, s2 = 0;
        if (y < sq3 * x - sq3)
            s1 = 2;
        else if (y < sq3 * x)
            s1 = 1;
        if (y > -sq3 * x + 2 * sq3)
            s2 = 2;
        else if (y > -sq3 * x + sq3)
            s2 = 1;

        // BCD=0,ACD=1,    ABD=2,ABC=3
        if (s1 == 0) {
            if (s2 == 0) {
                if (y > sq3 / 2)
                    res = 0;
                else
                    res = 1;
            } else if (s2 == 1)
                res = 3;
        } else if (s1 == 1) {
            if (s2 == 0)
                res = 3;
            else if (s2 == 1) {
                if (y > sq3 / 2)
                    res = 1;
                else
                    res = 0;
            } else
                res = 2;
        } else {
            if (s2 == 1)
                res = 2;
            else if (s2 == 2) {
                if (y > sq3 / 2)
                    res = 0;
                else
                    res = 1;
            }
        }

        return res;
    };

    cout << (solve(a + 1, da, la) == solve(b + 1, db, lb) ? "YES" : "NO") << endl;
}
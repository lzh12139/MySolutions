#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
struct node
{
    int n;
    int nextt[5], val[5];
    int fa, son;
    node()
    {
        n = fa = 0;
        son = 1;
        for (int i = 1; i <= 4; i++)
            nextt[i] = val[i] = 0;
    }
} a[5010];
int cnt = 1;

void pushup(int x, int val)
{
    if (a[x].n == 3)
    {
        if (a[x].fa)
        {
            pushup(a[x].fa, a[x].val[2]);
            int doo = 0;
            for (int i = 1; i <= a[x].n; i++)
                if (val < a[x].val[i])
                {
                    doo = 1;
                    
                    break;
                }
        }
        else
        {
            a[++cnt].n = 1, a[cnt].val;
        }
    }
    else
    {
    }
}

void work(int x, int val)
{
    if (a[x].son)
    {
        if (a[x].n < 3)
        {
            int doo = 0;
            for (int i = 1; i <= a[x].n; i++)
            {
                if (val < a[x].val[i])
                {
                    doo++;
                    a[x].nextt[a[x].n + 2] = a[x].nextt[a[x].n + 1];
                    for (int o = a[x].n; o >= i; o--)
                        a[x].val[o + 1] = a[x].val[o], a[x].nextt[o + 1] = a[x].nextt[o];
                    a[x].n++;
                    a[x].val[i] = val, a[x].nextt[i] = 0;
                    break;
                }
            }
            if (!doo)
                a[x].val[++a[x].n] = val;
        }
        else
        {
            if (a[x].fa == 0 || a[a[x].fa].n == 3)
            {
                a[++cnt].n = 1, a[cnt].val[1] = a[x].val[1], a[cnt].fa = x;
                a[++cnt].n = 1, a[cnt].val[1] = a[x].val[3], a[cnt].fa = x;
                a[x].n = 1, a[x].nextt[1] = cnt - 1, a[x].nextt[2] = cnt, a[x].val[1] = a[x].val[2], a[x].son = 0;
                if (val < a[x].val[1])
                    work(a[x].nextt[1], val);
                else
                    work(a[x].nextt[2], val);
            }
            else
            {
                if (a[a[x].fa].n != 0)
                    pushup(a[x].fa, a[x].val[2]);

                a[++cnt].n = 1, a[cnt].val[1] = a[x].val[1], a[x].fa = x;
                a[x].n = 1, a[x].val[1] = a[x].val[3], a[x].son = 0;

                if (val < a[cnt].val[3])
                    a[cnt].val[2] = a[cnt].val[1], a[cnt].val[1] = val, a[cnt].n++;
                else if (val < a[x].val[2])
                    a[cnt].val[2] = val, a[cnt].n++;
                else if (val < a[x].val[1])
                    a[x].val[2] = a[x].val[1], a[x].val[1] = val, a[x].n++;
                else
                    a[x].val[2] = val, a[x].n++;
            }
        }
    }
    else
    {
        int doo = 0;
        for (int i = 1; i <= a[x].n; i++)
            if (val < a[x].val[i])
            {
                work(a[x].nextt[1], val);
                doo++;
                break;
            }
        if (!doo)
            work(a[x].nextt[a[x].n + 1], val);
    }
}

void out(int x)
{
    if (x == 0)
        return;
    for (int i = 1; i <= a[x].n; i++)
        printf("%d ", a[x].val[i]);
    printf("\n");
    if (!a[x].son)
        for (int i = 1; i <= a[x].n + 1; i++)
            out(a[x].nextt[i]);
}

int main()
{
    freopen("in1.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for (int qaq = 1; qaq <= t; qaq++)
    {

        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            a[i] = node();
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            work(1, x);
            printf("i=%d %d------------------------\n", i, x);
            out(1);
            printf("\n");
        }
        printf("Case #%d:\n", qaq);
        out(1);
    }
}

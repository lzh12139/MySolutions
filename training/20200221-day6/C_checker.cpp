#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int a[1000], que[1000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        a[i] = rand() % 10000 + 1;
    printf("a[]= ");
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    printf("\n");
    while (1) {
        int q;
        scanf("%d", &q);
        if (q == 1) {
            int x;
            scanf("%d", &x);
            printf("ans: %d\n", a[x]);
        } else {
            int k;
            scanf("%d", &k);
            for (int i = 1; i <= k; i++)
                scanf("%d", &que[i]);
            printf("ans: ");
            for (int i = 1; i <= k; i++)
                for (int j = i + 1; j <= k; j++)
                    printf("%d ", abs(que[i] - que[j]));
            printf("\n");
        }
    }
}
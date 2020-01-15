#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> que;
struct myset {
    int arr[300001];
    int size;
    myset()
    {
        memset(arr, 0, sizeof(arr));
        size = 0;
    }
    void insert(int val)
    {
        arr[val]++;
        if (arr[val] == 1)
            size++;
    }
    void erase(int val)
    {
        arr[val]--;
        if (arr[val] == 0)
            size--;
    }
} Set;
int a[300001];
bool sol[300001];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        Set.insert(a[i]);
    }
    int last = -1;
    int j = 0;
    for (int i = 0; i < k; ++i) {
        while (j < n && Set.size == k) {
            Set.erase(a[j]);
            que.push(make_pair(a[j], j));
            ++j;
        }
        while (!que.empty()) {
            pii tmp = que.top();
            que.pop();
            if (!sol[tmp.first] && tmp.second > last) {
                last = tmp.second;
                sol[tmp.first] = true;
                Set.insert(tmp.first);
                printf("%d ", tmp.first);
                break;
            }
        }
    }
}
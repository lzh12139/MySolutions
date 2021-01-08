#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int a[N];
int main()
{
    int n;
    cin >> n;
  	// assert(n!=1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
	cout<<a[n/2]<<endl;
}
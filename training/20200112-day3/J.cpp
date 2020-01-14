#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define ff first
#define ss second

typedef unsigned long long uint64;
uint64 seed;
uint64 state[2] = { seed, seed ^ 0x7263d9bd8409f526 };
uint64 xoroshiro128plus(uint64 s[2]) {
    uint64 s0 = s[0];
    uint64 s1 = s[1];
    uint64 result = s0 + s1;
    s1 ^= s0;
    s[0] = ((s0<<55) | (s0>>9)) ^ s1 ^ (s1<<14);
    s[1] = (s1<<36) | (s1>>28);
    return result;
}

int main(){
    seed=3641603982383516983;
    state[0]=seed;
    state[1]=seed ^ 0x7263d9bd8409f526;
    uint64 addd=(1ll<<50)-1;
    for(int i=1;i<=500;i++)
        cout<< (((uint64)xoroshiro128plus(state))&addd) <<endl;
}
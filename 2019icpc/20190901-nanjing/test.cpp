#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <string>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
typedef pair<int, int> pii;

int main()
{
    int x = 5, c = 110;
    while (x != 223)
    {
        x = x * 5 % 233;
        c++;
    }
    printf("%d\n", c);
}
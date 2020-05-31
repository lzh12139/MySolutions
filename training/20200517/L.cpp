#include <bits/stdc++.h>
using namespace std;

const char s1[] = { "aiyeou" };
const char s2[] = { "bkxznhdcwgpvjqtsrlmf" }; // 20
int main()
{
    ios::sync_with_stdio(0);
    char c;
    while (c = getchar()) {
        if (c == -1)
            break;
        if ('a' <= c && c <= 'z') {
            int ok = 0;
            for (int i = 0; i < 6; i++)
                if (c == s1[i]) {
                    putchar(s1[(i + 3) % 6]);
                    ok = 1;
                    break;
                }
            if (!ok)
                for (int i = 0; i < 20; i++)
                    if (c == s2[i]) {
                        putchar(s2[(i + 10) % 20]);
                        ok = 1;
                        break;
                    }
        } else if ('A' <= c && c <= 'Z') {
            const int add = 'A' - 'a';
            int ok = 0;
            for (int i = 0; i < 6; i++)
                if (c - add == s1[i]) {
                    putchar(s1[(i + 3) % 6] + add);
                    ok = 1;
                    break;
                }
            if (!ok)
                for (int i = 0; i < 20; i++)
                    if (c - add == s2[i]) {
                        putchar(s2[(i + 10) % 20] + add);
                        ok = 1;
                        break;
                    }
        } else
            putchar(c);
    }
}
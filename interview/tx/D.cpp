#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    stack<int> in, out;
    while (n--) {
        char s[10];
        scanf("%s", s + 1);
        if (s[2] == 'd') { // add
            int tmp;
            scanf("%d", &tmp);
            if(in.empty()){
                while (!out.empty()) {
                    in.push(out.top());
                    out.pop();
                }
            }
            out.push(tmp);
        } else if (s[2] == 'o') { // poll
            if (in.empty()) {
                while (!out.empty()) {
                    in.push(out.top());
                    out.pop();
                }
            }
            in.pop();
        } else { // peek
            if (in.empty()) {
                while (!out.empty()) {
                    in.push(out.top());
                    out.pop();
                }
            }
            printf("%d\n", in.top());
        }
    }
}
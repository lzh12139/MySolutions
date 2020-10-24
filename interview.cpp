#include <bits/stdc++.h>
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 33-221
/*
033
221
-200+ 10+ 2=-188
*/
string solve(string a, string b)
{
    bool neg = 0; // 是否为负数
    string res = "";
    if (a.size() < b.size()) {
        neg = 1;
    } else if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++)
            if (a[i] < b[i]) {
                neg = 1; //  230 222
                break;
            } else if (a[i] > b[i]) {
                break;
            }
    }

    if (neg == 1) {
        swap(a, b);
    }
    // 此时 a.size()>=b.size()
    for (int i = a.size() - 1, j = b.size() - 1, less = 0; i >= 0; i--, j--) {
        int tmp = (j >= 0 ? a[i] - b[j] : a[i] - '0') - less; // 这个是当前这一位的计算结果
        less = 0;
        if (tmp < 0) {
            // 借一位
            less = 1;
            tmp += 10;
        }
        res += char(tmp + '0');
    }

    while (res.back() == '0')
        res.erase(--res.end());
    if (neg)
        res += '-';
    reverse(res.begin(), res.end());

    return res;
}

int main()
{
    string a;
    string b;
    cin >> a >> b;
    string res = solve(a, b);
    cout << res << endl;
}
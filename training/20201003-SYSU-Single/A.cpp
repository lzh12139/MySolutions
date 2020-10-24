#include <bits/stdc++.h>
using namespace std;

struct node {
    int t;
    string atk, def;
};

vector<string> split(string str, char sp)
{
    vector<string> ret;
    int last = 0;
    str = str + sp;
    for (int i = 0; i < str.size(); i++)
        if (str[i] == sp) {
            ret.emplace_back(str.substr(last, i - last));
            // cout<<str.substr(last, i - last)<<"*** \n";
            last = i + 1;
        }
    return ret;
}
int to_int(string str)
{
    int ret = 0;
    for (auto i : str)
        ret = ret * 10 + i - '0';
    return ret;
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        mp[str] = i - 1;
    }
    vector<node> v;
    for (int i = 1; i <= m; i++) {
        string str;
        cin >> str;
        auto ret = split(str, ',');
        node nod;
        if (ret[2] == "win") {
            auto tim = split(ret[3], ':');
            nod.t = to_int(tim[0]) * 60 + to_int(tim[1]);
            nod.atk = ret[0], nod.def = ret[1];
            v.emplace_back(nod);
        }
    }

    sort(v.begin(), v.end(), [](node a, node b) {
        return a.t < b.t;
    });
    for (auto i : v) {
        int a = mp[i.atk], b = mp[i.def];
        mp[i.atk] = min(a, b), mp[i.def] = max(a, b);
    }
    vector<string> ans(n);
    for (auto i : mp)
        ans[i.second] = i.first;
    for (auto i : ans)
        cout << i << endl;
}
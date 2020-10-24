#include <bits/stdc++.h>
using namespace std;
#define ll long long

map<int, string> mp;
set<int> st;
int num = 0, vis[1000010];
int get()
{
    while (!st.empty() && vis[*st.begin()]) {
        st.erase(st.begin());
    }
    if (st.empty()) {
        while (vis[num])
            num++;
        return vis[num] = 1, num++;
    }

    int ret = *st.begin();
    st.erase(st.begin());
    return vis[ret] = 1, ret;
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        memset(vis, 0, sizeof vis);
        st.clear();
        mp.clear();
        num = 0;

        int n;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            string str, name;
            cin >> str;
            if (str == "open") {
                cin >> name;
                int x = get();
                mp[x] = name;
                cout << x << endl;
            } else if (str == "dup") {
                int tmp;
                cin >> tmp;
                int x = get();
                mp[x] = mp[tmp];
                cout << x << endl;
            } else if (str == "dup2") {
                int fd, newfd;
                cin >> fd >> newfd;
                vis[newfd] = 1;
                mp[newfd] = mp[fd];
                st.erase(newfd);
            } else if (str == "close") {
                int fd;
                cin >> fd;
                st.insert(fd);
                vis[fd] = 0;
            } else {
                int fd;
                cin >> fd;
                cout << mp[fd] << endl;
            }
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
const long N = 10005;
const long M = 2e6 + 1;
int t[N];
int p[N];
int d[N];
int n, m;
vector<int> a[N];
queue<int> Q;
vector<int> c[N];
int res;

void input() {
    int u, v;
    res = 0;
    memset(t, 0, sizeof(t));
    cin >> n >> m;
    for(int  i = 0; i < n; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        a[v].push_back(u);
        c[u].push_back(v);
        p[v]++;
    }
}

void solve() {
    for(int i = 0; i < n; i++) {
        if(p[i] == 0)
            Q.push(i);
            t[i] = 0;
    }
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(int i = 0; i < a[u].size(); i++) {
            int s = a[u][i];
            t[u] = max(t[u], t[s]+d[s]);
        }
        for(int i = 0; i < c[u].size(); i++) {
            int v = c[u][i];
            p[v]--;
            if(p[v] == 0)
                Q.push(v);
        }
    }
    for(int i = 0; i < n; i++) {
        res = max(res, t[i]+d[i]);
    }
    cout << res;
}

int main() {
    input();
    solve();
}
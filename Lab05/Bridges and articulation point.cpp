#include <bits/stdc++.h>
using namespace std;
const long N = 100000 + 7;
int n, m;
vector<int> a[N];
bool visited[N];
int num[N];
int low[N];
int t;
vector<pair<int, int>> bridges;

void input() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
}

void dfs(int s, int ps) {
    t++;
    num[s] = t;
    low[s] = num[s];
    visited[s] = true;
    for(int i = 0; i < int(a[s].size()); i++) {
        int v = a[s][i];
        if(v == ps)
            continue;
        if(visited[v]) {
            low[s] = min(low[s], num[v]);
        }
        else {
            dfs(v, s);
            low[s] = min(low[s], low[v]);
            if(low[v] > num[s])
                bridges.push_back(make_pair(s, v));
        }
    }
}

void solve() {
    t = 0; 
    for(int s = 0; s < n; s++) {
        if(!visited[s])
            dfs(s, -1);
    }
    for(int i = 0; i < bridges.size(); i++) {
        cout << bridges[i].first << bridges[i].second << endl;
    }
}

int main() {
    input();
    memset(visited, false, sizeof(visited));
    solve();
    return 0;
}

//Only bridges done, arculation not yet

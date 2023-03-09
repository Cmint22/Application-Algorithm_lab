#include <bits/stdc++.h>
using namespace std;
const int MAX = 100005;
int n, L1, L2, res;
int a[MAX], S[MAX];

void input() {
    cin >> n >> L1 >> L2;
    for(int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    S[0] = a[0];
    res = S[0];
    for(int i = 1; i < n; i++) {
        int max_j = 0;
        for(int j = i-L2; j <= i-L1; j++) {
            if(j >= 0)
                max_j = max(max_j, S[j]);
        }
        S[i] = max_j + a[i];
        res = max(res, S[i]);
    }
}

int main() {
    input();
    solve();
    cout << res;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n, lmin, lmax;
const ll mod = 1e9 + 7;
ll dp[1005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> lmin >> lmax;
    dp[0] = 1;
    for(int i = 1; i <= n + 1; ++i) {
        for(int k = lmin; k <= i - 1 && k <= lmax; ++k) {
            dp[i] = (dp[i] + dp[i - k - 1])%mod;
        }
    }
    cout << dp[n - 1] + 2*dp[n] + dp[n + 1];
    return 0;
}
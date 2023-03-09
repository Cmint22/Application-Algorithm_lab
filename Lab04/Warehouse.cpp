#include <bits/stdc++.h>
using namespace std;

int n, T, D, a[1001], t[1001], dp[1001][101], ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T >> D;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> t[i];
    for(int i = 0; i < n; ++i) {
        for(int time = 0; time <= T; ++time) {
            for(int dist = 1; dist <= D; ++dist) {
                if(dist < i)
                    break;
                if(t[i] > time)
                    continue;
                dp[i][time] = max(dp[i][time], a[i] + dp[i - dist][time - t[i]]);
                ans = max(dp[i][time], ans);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, x[101], y[101];
ll t = 0;

void TRY(int k, int sum) {
    for(int i = 1; i <= (m - sum) / x[k]; ++i) {
        y[k] = i;
        sum += x[k] * y[k];
        if(sum <= m) {
            if(k == n - 1) {
                if(sum == m) ++t;
            } else TRY(k + 1, sum);
        }
        sum -= x[k] * y[k];
        y[k] = 0;
    }
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    TRY(0, 0);
    cout << t << endl;
}

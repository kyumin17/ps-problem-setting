#include <bits/stdc++.h>

using namespace std;

int v[2001][2001];
int dp1[2001][2001];
int dp2[2001][2001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> v[i][j];
        sort(v[i], v[i]+m);
    }

    for (int i = 0; i < m; i++) {
        dp1[0][i] = -v[0][i];
        dp2[0][i] = v[0][i];
    }
    for (int i = 1; i < m; i++) dp1[0][i] = min(dp1[0][i], dp1[0][i-1]);
    for (int i = m-2; i >= 0; i--) dp2[0][i] = min(dp2[0][i], dp2[0][i+1]);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int val = v[i][j];
            int high = lower_bound(v[i-1], v[i-1] + m, val) - v[i-1];
            int low = high - 1;
            int t = 2 * 1e9;
            if (low >= 0) t = min(t, dp1[i-1][low] + val);
            if (high < m) t = min(t, dp2[i-1][high] - val);
            dp1[i][j] = dp2[i][j] = t;
            if (i < n-1) {
                dp1[i][j] -= val; dp2[i][j] += val;
            }
        }
        for (int j = 1; j < m; j++) dp1[i][j] = min(dp1[i][j], dp1[i][j-1]);
        for (int j = m-2; j >= 0; j--) dp2[i][j] = min(dp2[i][j], dp2[i][j+1]);
    }

    cout << dp1[n-1][m-1];
}
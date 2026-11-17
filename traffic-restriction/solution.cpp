#include <bits/stdc++.h>

using namespace std;

int v[501][501];
int rt[501];
int smn[501][501], emn[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v[i][j] = emn[i][j] = smn[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= n; i++) cin >> rt[i];
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a][b] = v[b][a] = c;
    }

    for (int k = 1; k <= n; k++) {
        bool vis[n+1];
        fill(vis, vis+n+1, 0);
        smn[k][k] = 0;
        for (int i = 1; i <= n; i++) {
            int cur = 1;
            for (int j = 1; j <= n; j++) {
                if (vis[cur] || (!vis[j] && smn[k][j] < smn[k][cur])) cur = j;
            }
            vis[cur] = 1;
            for (int j = 1; j <= n; j++) {
                if (v[cur][j] == 1e9) continue;
                int d = smn[k][cur] + v[cur][j];
                if (rt[k] - rt[j] > d) continue;
                smn[k][j] = min(smn[k][j], d);
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        bool vis[n+1];
        fill(vis, vis+n+1, 0);
        emn[k][k] = 0;
        for (int i = 1; i <= n; i++) {
            int cur = 1;
            for (int j = 1; j <= n; j++) {
                if (vis[cur] || (!vis[j] && emn[k][j] < emn[k][cur])) cur = j;
            }
            vis[cur] = 1;
            for (int j = 1; j <= n; j++) {
                if (v[cur][j] == 1e9) continue;
                int d = emn[k][cur] + v[cur][j];
                if (rt[j] - rt[k] < d) continue;
                emn[k][j] = min(emn[k][j], d);
            }
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int s, d, t;
        cin >> s >> d >> t;
        int ans = 1e9;
        for (int j = 1; j <= n; j++) {
            if (rt[j] - smn[j][s] < t) continue;
            ans = min(ans, smn[j][s] + emn[j][d]);
        }
        if (ans < 1e9) cout << ans + t << "\n";
        else cout << -1 << "\n";
    }
}

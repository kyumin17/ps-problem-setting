#include <iostream>

using namespace std;

int arr[4001][4001];
int pfx[4001][4001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, t; cin >> n >> t;

    for (int i = 0; i < n; i++) {
        int a, c; cin >> a >> c;
        arr[a][c]++;
    }

    for (int i = 1; i <= 4000; i++) {
        for (int j = 1; j <= 4000; j++) {
            pfx[i][j] = arr[i][j] + pfx[i-1][j] + pfx[i][j-1] - pfx[i-1][j-1];
        }
    }

    for (int i = 0; i <= 8000; i++) {
        for (int j = max(0, i-4000); j <= min(i, 4000); j++) {
            if (pfx[j][i-j] >= t) {
                cout << j << " " << i-j;
                return 0;
            }
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    int t = 0;
    if (n % 2 == 0) t += (m + 1) / 2;
    if (m % 2 == 0) t += (n + 1) / 2;
    if (t % 2) cout << "ODD";
    else cout << "EVEN";
}
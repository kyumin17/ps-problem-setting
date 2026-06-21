#include <iostream>

using namespace std;

int main() {
    int n, m; cin >> n >> m;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    }

    if (sum + m >= 130) cout << "YES";
    else cout << "NO";
}
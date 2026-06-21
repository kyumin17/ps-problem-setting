#include <iostream>
using ll = long long;
#define MAX 100000

using namespace std;

ll query(int x) {
    cout << "? " << x << endl;
    ll res; cin >> res;
    return res;
}

int main() {
    ll n; cin >> n;

    ll mx = query(MAX);
    ll base = mx - query(MAX - 1);

    if (base != n) {
        cout << "! " << MAX << endl;
        return 0;
    }

    int s = 1, e = MAX - 1;
    while (s < e) {
        int m = (s + e) / 2;

        if (mx - query(m) < base * (ll)(MAX - m)) s = m + 1;
        else e = m;
    }

    cout << "! " << e << endl;
}
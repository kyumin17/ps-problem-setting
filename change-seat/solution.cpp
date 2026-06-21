#include <iostream>
#include <numeric>
using ll = long long;

using namespace std;

int main() {
    ll n; cin >> n;
    for (int i = 2; i < 100; i++) {
        if (gcd(i, n) != 1) continue;
        cout << i-1;
        break;
    }
}
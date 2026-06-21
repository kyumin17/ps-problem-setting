#include <iostream>
#define MOD 1'000'000'007
using ll = long long;

using namespace std;

int main() {
    int n, cnt = 0; string s; 
    cin >> n >> s;
    
    for (int i = 1; i < n; i++) {
        if (s[i-1] != s[i]) cnt++;
    }

    ll res = 1;
    for (int i = 1; i <= cnt; i += 2) res = (res * i) % MOD;
    if (cnt % 2) res *= 2;

    cout << res % MOD;
}
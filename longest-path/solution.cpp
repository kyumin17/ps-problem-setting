#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin >> n;
 
    long long t = 0;
    for (int i = 0; i < n; i++) {
        cout << 1 + t % n << " ";
        t += n / 2;
        if (i % 2 && n % 2 == 0) t--;
    }
}

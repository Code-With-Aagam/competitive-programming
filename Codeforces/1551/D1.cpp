#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        bool good = false;
        if (n % 2 == 1) {
            good = (k >= m / 2 and k % 2 == (m / 2) % 2);
        } else if (m % 2 == 1) {
            good = (k <= (m - 1) * n / 2 and k % 2 == 0);
        } else {
            good = (k % 2 == 0);
        }
        cout << (good ? "YES\n" : "NO\n");
    }
    return 0;
}
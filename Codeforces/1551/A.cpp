#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int c1 = n / 3, c2 = (n - c1) / 2;
        if ((n - c1) % 2 == 1) ++c1;
        cout << c1 << " " << c2 << "\n";
    }
    return 0;
}
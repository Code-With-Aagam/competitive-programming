#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> t = {"H", "2B", "3B", "HR"};
    vector<string> s(4);
    for (auto &e : s) cin >> e;
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    cout << (s == t ? "Yes" : "No");
    return 0;
}
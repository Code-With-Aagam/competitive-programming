#include <bits/stdc++.h>
using namespace std;

/**
 * Sequence containers (Arrays and Linked Lists):
 * - vector, deque, list, forward_list, array
 * 
 * Associative Containers (Binary Tree):
 * - set and multiset
 * - map and multimap
 * 
 * Unordered Containers (Hash Table):
 * - unordered_set and unordered_multiset
 * - unordered_map and unordered_multimap
 */

int main() {
    
    // vector
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    for (auto ele : v) cout << ele << " ";
    cout << "\n";

    // deque
    deque<int> d;
    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    for (auto ele : d) cout << ele << " ";
    cout << "\n";

    // list
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(3);
    // l.splice(l.begin(), l, l.begin());
    for (auto ele : l) cout << ele << " ";
    cout << "\n";

    // set / multiset
    set<int> s;
    s.insert(1);
    s.insert(-1);
    s.insert(0);
    for (auto ele : s) cout << ele << " ";
    cout << "\n";

    // unordered_set / unordered_multiset
    unordered_set<int> us;
    us.insert(1);
    us.insert(-1);
    us.insert(0);
    for (auto ele : us) cout << ele << " ";
    cout << "\n";

    return 0;
}
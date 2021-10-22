#include <bits/stdc++.h>
using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> positions;
public:
    RandomizedSet() {
        nums.clear();
        positions.clear();
    }
    
    bool insert(int val) {
        if (positions.count(val) > 0) {
            return false;
        } else {
            positions[val] = nums.size();
            nums.push_back(val);
            return true;
        }
    }
    
    bool remove(int val) {
        if (positions.count(val) == 0) {
            return false;
        } else {
            int index = positions[val];
            if (index != nums.size() - 1) {
                int last = nums[nums.size() - 1];
                nums[index] = last;
                positions[last] = index;
            }
            positions.erase(val);
            nums.pop_back();
            return true;
        }
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
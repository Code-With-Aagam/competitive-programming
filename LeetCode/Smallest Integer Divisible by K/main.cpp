class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k == 1) return 1;
        else if (k % 2 == 0) return -1;
        int currMod = 1, ans = 1, rep = 0;
        while (currMod != 0 && rep < 100000) {
            currMod *= 10;
            currMod += 1;
            currMod %= k;
            ++ans;
            ++rep;
        }
        return currMod == 0 ? ans : -1;
    }
};
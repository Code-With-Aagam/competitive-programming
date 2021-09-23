class Solution {
private:
    unordered_map<int, string> cache;
    unordered_map<string, string> revCache;
    unordered_map<string, string> invCache;    

    string reverseString(const string &s) {
        if (revCache.count(s) > 0) return revCache[s];
        string ans = s;
        reverse(begin(ans), end(ans));
        revCache[s] = ans;
        return ans;
    }

    string invertString(const string &s) {
        if (invCache.count(s) > 0) return invCache[s];
        string ans = "";
        for (const auto &ch : s) {
            if (ch == '0') ans += "1";
            else ans += "0";
        }
        invCache[s] = ans;
        return ans;
    }

    string findString(int n) {
        if (cache.count(n) > 0) return cache[n];
        if (n == 1) return "0";
        else return cache[n] = findString(n - 1) + "1" + reverseString(invertString(findString(n - 1)));
    }

public:
    char findKthBit(int n, int k) {
        string s = findString(n);
        return s[k - 1];
    }
};
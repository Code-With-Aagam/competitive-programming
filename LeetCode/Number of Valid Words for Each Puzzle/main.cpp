class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        vector<int> ans;
        auto encode = [&](const string &word) -> int {
            int code = 0;
            for (const auto &ch : word) {
                code |= (1 << (ch - 'a'));
            }
            return code;
        };
        map<int, int> mp;
        for (const auto &word : words) {
            mp[encode(word)]++;
        }
        for (const auto &puzzle : puzzles) {
            int code = encode(puzzle), subcode = code, first = (1 << (puzzle[0] - 'a')), curr = 0;
            while (subcode > 0) {
                if (subcode & first) {
                    curr += mp[subcode];
                }
                subcode = ((subcode - 1) & code);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};
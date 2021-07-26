class Solution {
   public:
    string maximumNumber(string num, vector<int> &change) {
        int n = num.size(), i = 0;
        while (i < n && (num[i] - '0') >= change[num[i] - '0']) {
            ++i;
        }
        while (i < n && (num[i] - '0') <= change[num[i] - '0']) {
            num[i] = change[num[i] - '0'] + '0';
            ++i;
        }
        return num;
    }
};
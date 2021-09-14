class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> ans(5, 0);
        for (const auto &ch : text) {
            switch (ch) {
                case 'a':
                    ++ans[0];
                    break;
                case 'b':
                    ++ans[1];
                    break;
                case 'l':
                    ++ans[2];
                    break;
                case 'n':
                    ++ans[3];
                    break;
                case 'o':
                    ++ans[4];
            }
        }
        ans[2] /= 2;
        ans[4] /= 2;
        return *min_element(cbegin(ans), cend(ans));
    }
};
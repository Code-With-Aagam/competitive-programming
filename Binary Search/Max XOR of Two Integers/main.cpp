class TrieNode {
    TrieNode* children[2] = { nullptr };
public:
    bool containsKey(int bit) {
        return children[bit] != nullptr;
    }

    TrieNode* getNextNode(int bit) {
        return children[bit];
    }

    void createNode(int bit) {
        children[bit] = new TrieNode();
    }
};

class Trie {
    const int MAX_BITS = 60;
    TrieNode* root = new TrieNode();

public:
    void insertNumber(int num) {
        TrieNode* node = root;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = ((num & (1LL << i)) > 0 ? 1 : 0);
            if (not node -> containsKey(bit)) {
                node -> createNode(bit);
            }
            node = node -> getNextNode(bit);
        }
    }

    int getMaximumXOR(int x) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = MAX_BITS; i >= 0; --i) {
            int bit = ((x & (1LL << i)) > 0 ? 1 : 0);
            if (node -> containsKey(1 - bit)) {
                ans |= (1LL << i);
                node = node -> getNextNode(1 - bit);
            } else {
                node = node -> getNextNode(bit);
            }
        }
        return ans;
    }
};

int solve(vector<int>& nums) {
    Trie* trie = new Trie();
    for (const auto &ele : nums) trie -> insertNumber(ele);
    int ans = 0;
    for (const auto &ele : nums) ans = max(ans, trie -> getMaximumXOR(ele));
    return ans;
}
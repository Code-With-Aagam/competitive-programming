class TrieNode {
    TrieNode* children[26] = { nullptr };
    bool lastCharacter = false;

    int getIndex(const char &ch) {
        return ch - 'a';
    }
public:
    bool containsKey(const char &ch) {
        int index = getIndex(ch);
        return children[index] != nullptr;
    }

    TrieNode* getNextNode(const char &ch) {
        int index = getIndex(ch);
        return children[index];
    }

    void createNode(const char &ch) {
        int index = getIndex(ch);
        children[index] = new TrieNode();
    }

    void markLastCharacter() {
        lastCharacter = true;
    }

    bool isLastCharacter() {
        return lastCharacter;
    }
};

class Trie {
    TrieNode* root = new TrieNode();

public:
    void insertWord(const string &word) {
        TrieNode* node = root;
        for (const auto &ch : word) {
            if (not node -> containsKey(ch)) {
                node -> createNode(ch);
            }
            node = node -> getNextNode(ch);
        }
        node -> markLastCharacter();
    }

    bool contains(const string &word) {
        TrieNode* node = root;
        for (const auto &ch : word) {
            if (not node -> containsKey(ch)) {
                return false;
            }
            node = node -> getNextNode(ch);
        }
        return node -> isLastCharacter();
    }

    bool startsWith(const string &word) {
        TrieNode* node = root;
        for (const auto &ch : word) {
            if (not node -> containsKey(ch)) {
                return false;
            }
            node = node -> getNextNode(ch);
        }
        return true;
    }
};
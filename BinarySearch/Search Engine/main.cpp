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

class SearchEngine {
	TrieNode* root = new TrieNode();

	bool exists(string &word, int index, TrieNode* node) {
		if (index == word.size()) return node -> isLastCharacter();
		if (word[index] == '.') {
			for (char ch = 'a'; ch <= 'z'; ++ch) {
				word[index] = ch;
				if (exists(word, index, node)) return true;
			}
			word[index] = '.';
		} else {
			if (node -> containsKey(word[index])) {
				return exists(word, index + 1, node -> getNextNode(word[index]));
			} else {
				return false;
			}
		}
		return false;
	}
public:
	void add(string word) {
		TrieNode* node = root;
		for (const auto &ch : word) {
			if (not node -> containsKey(ch)) {
				node -> createNode(ch);
			}
			node = node -> getNextNode(ch);
		}
		node -> markLastCharacter();
	}

	bool exists(string word) {
		return exists(word, 0, root);
	}
};
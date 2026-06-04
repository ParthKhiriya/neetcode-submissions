class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode () {
        endOfWord = false;
        for(int i=0; i<26; i++) {
            children[i] = nullptr;
        }
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode ();
    }
    
    void addWord(string word) {
        TrieNode* curr = root; 
        for(char c: word) {
            int index = c - 'a';
            if(!curr->children[index]) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

private: 
    bool dfs (string word, int j, TrieNode* root) {
        TrieNode* curr = root;

        for(int i=j; i<word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* child : curr->children) {
                    if(child != nullptr && dfs(word, i+1, child)) {
                        return true;
                    }
                }
                return false;
            } else {
                int index = c - 'a';
                if(!curr->children[index]) {
                    return false;
                }
                curr = curr->children[index];
            }
        }

        return curr->endOfWord;
    }
};

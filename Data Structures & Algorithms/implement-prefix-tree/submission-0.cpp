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

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode ();
    }
    
    void insert(string word) {
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
        TrieNode* curr = root;
        for(char c: word) {
            int index = c - 'a';
            if(!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c: prefix) {
            int index = c - 'a';
            if(!curr->children[index]) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};

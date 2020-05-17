/*

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.

*/

class Trie {
public:
    Trie *children[26];
    bool isEndofWord;
    /** Initialize your data structure here. */
    Trie() {
        for (int i=0;i<26;++i) {
            children[i] = nullptr;
        }
        isEndofWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.size();
        Trie *root = this;
        for(int i=0;i<size;++i) {
            if(!root->children[word[i]-'a']) {
                root->children[word[i]-'a'] = new Trie();
            }
            root = root->children[word[i]-'a'];
        }
        root->isEndofWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
       Trie *root = this;
        int size = word.size();
        for (int i=0;i<size;++i) {
            if (!root->children[word[i]-'a']) return false;
            root = root->children[word[i]-'a'];
        }
        return root->isEndofWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie *root = this;
        int size = prefix.size();
        for (int i=0;i<size;++i) {
            if (!root->children[prefix[i]-'a']) return false;
            root = root->children[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
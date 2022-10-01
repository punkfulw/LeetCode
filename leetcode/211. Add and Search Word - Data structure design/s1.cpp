// OJ: https://leetcode.com/problems/add-and-search-word-data-structure-design/
// Author: github.com/punkfulw
// Time:
//      WordDictionary: O(1)
//      addWord: O(W)
//      search: O(26^3) there's at most 3 '.' in a word
// Space: O(NW)
class TrieNode {
public:
    int end;
    TrieNode* child[26];
    
    TrieNode () : end(0){
        for (int i = 0; i < 26; i++)
            child[i] = nullptr;
    }
};
class WordDictionary {
public:
    TrieNode *root = new TrieNode();
    
    WordDictionary() {
    }
    
    void addWord(string word) {
        TrieNode *node = root;
        for (auto c: word){
            if (node->child[c - 'a'] == nullptr)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->end = 1;
    }
    
    bool check(TrieNode *node, string &word, int idx){
        if (idx == word.size())
            return node->end == 1;
        bool ret = false;
        char c = word[idx];     
        
        if (c == '.'){
            for (int i = 0; i < 26 && !ret; i++){
                if (node->child[i])
                    ret |= check(node->child[i], word, idx + 1);
            }
        }
        else {
            if (node->child[c - 'a'] == nullptr)
                    return false;
                ret |= check(node->child[c - 'a'], word, idx + 1);
        }
            
        return ret;
    }
    
    bool search(string word) {
        TrieNode *node = root;
        return check(node, word, 0);
    }
};

// OJ: https://leetcode.com/problems/implement-trie-prefix-tree/
// Author: github.com/punkfulw
// Time: O(W) for word length in insert/search/startsWith
// Space:
//   insert: O(W)
//   search/startsWith: O(1)
class Trie {
    struct TrieNode{
        bool endword = false;
        TrieNode* child[26] = {};
        
    } root; 
public:
    void insert(string word) {
        auto p = &root;
        for (auto c: word){
            if (p->child[c - 'a'] == NULL)
                p->child[c - 'a'] = new TrieNode;
            p = p->child[c - 'a'];
        }
        p->endword = true;
    }
    bool search(string word) {
        auto p = &root;
        for (auto c: word){
            if (p->child[c - 'a'] == NULL)
                return false;
            p = p->child[c - 'a'];
        }
        return p->endword;
    }
    bool startsWith(string prefix) {
        auto p = &root;
        for (auto c: prefix){
            if (p->child[c - 'a'] == NULL)
                return false;
            p = p->child[c - 'a'];
        }
        return true;
    }
};

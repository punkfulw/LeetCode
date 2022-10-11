// OJ: https://leetcode.com/problems/longest-word-in-dictionary/
// Author: github.com/punkfulw
// Time: O(N+W)
// Space: O(N+w)
class TrieNode {
public:
    TrieNode* child[26];
    int end;
    
    TrieNode(){
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
        end = 0;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    string ans;
    
    void build(string &s){
        TrieNode* node = root;
        for (auto &c: s){
            if (node->child[c - 'a'] == NULL)
                node->child[c - 'a'] = new TrieNode();
            node = node->child[c - 'a'];
        }
        node->end = 1;
    }
    
    void dfs(string &s, TrieNode* node){
        if (ans.size() == s.size())
            ans = min(s, ans);
        if (s.size() > ans.size())
            ans = s;
        
        for (int i = 0; i < 26; i++){
            if (node->child[i] && node->child[i]->end){
                s += ('a' + i);
                dfs(s, node->child[i]);
                s.pop_back();
            }
        }
    }
    
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());

        for (auto &w: words)
            build(w);
        string s = "";
        dfs(s, root);
        
        return ans;
    }
};

// OJ: https://leetcode.com/problems/find-and-replace-pattern/
// Author: github.com/punkfulw
// Time: O(N*L) , where N is the number of words and L is the length of each word.
// Space: O(N*L)
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans {};
        pattern = nomalize(pattern);
        for (auto word: words){
            if (nomalize(word) == pattern)
                ans.push_back(word);
        }
        return ans;
    }
    
    string nomalize(string word){
        unordered_map<char, char> mp;
        char c = 'a';
        
        for (auto ch: word)
            if (!mp.count(ch))
                mp[ch] = c++;
        
        for (auto& ch: word)
            ch = mp[ch];
        return word;
    }
};

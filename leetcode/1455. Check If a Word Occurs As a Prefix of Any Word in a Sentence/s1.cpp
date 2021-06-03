// OJ: https://leetcode.com/problems/check-if-a-word-occurs-as-a-prefix-of-any-word-in-a-sentence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        int ans = 1;
        string cur;
        int n = searchWord.size();
        
        while (ss >> cur){
            if (searchWord == cur.substr(0, n))
                return ans;
            ans++;
        }
        return -1;
    }
};

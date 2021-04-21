// OJ: https://leetcode.com/problems/truncate-sentence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string truncateSentence(string s, int k) {
        string ans;
        for (char &c: s){
            if (c == ' ')
                k--;
            if (k == 0)
                break;
            ans.push_back(c);
        }
        return ans;
    }
};

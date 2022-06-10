// OJ: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(C) where C is the range of character set
// Ref: https://discuss.leetcode.com/topic/24739/c-code-in-9-lines
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256, -1);
        int ans = 0, p = 0;
        for (int i = 0; i < s.size(); i++){
            p = max(pos[s[i]] + 1, p);    
            pos[s[i]] = i;
            ans = max(ans, i - p + 1);
        }
        return ans;
    }
};

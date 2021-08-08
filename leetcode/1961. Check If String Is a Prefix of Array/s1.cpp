// OJ: https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int n = s.size();
        string ans;
        int i = 0;
        while (ans.size() < n && i < words.size()){
            ans += words[i++];
        }
        return ans == s;
    }
};

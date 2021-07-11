// OJ: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/unique-length-3-palindromic-subsequences/discuss/1330165/Left-and-right-and-inbetween
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        vector<int> first(26, INT_MAX), last(26);
        
        for (int i = 0; i < s.size(); i++){
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }
        for (int i = 0; i < 26; i++)
            if (first[i] < last[i])
                ans += unordered_set<char> (s.begin() + first[i] + 1, s.begin() + last[i]).size();
        return ans;
    }
};

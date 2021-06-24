// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/longest-palindromic-substring/discuss/2923/Simple-C%2B%2B-solution-(8ms-13-lines)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size(), i = 0;
        int start_index, longest = 0;
        if (s.size() <= 1)
            return s;
        while (i < n){
            int st = i, ed = i;
            while (s[ed] == s[ed+1] && ed < n-1)
                ed++;
            i = ed+1;
            while (st > 0 && ed < n - 1 && s[st-1] == s[ed+1]){
                st--;
                ed++;
            }
            int cur = ed - st + 1;
            if (cur > longest){
                start_index = st;
                longest = cur;
            }
        }
        return s.substr(start_index, longest);
    }
};

// OJ: https://leetcode.com/problems/longest-palindromic-substring/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string longestPalindrome(string s) {
        int mx = 0, n = s.size();
        string ans;
        
        for (int i = 0; i < n; i++){
            int l = i, r = i + 1;
            while (l >= 0 && r < n){
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }
            if (r - l - 1 > mx){
                mx = r - l - 1;
                ans = s.substr(l + 1, r - l - 1);
            }
            l = i - 1, r = i + 1;
            while (l >= 0 && r < n){
                if (s[l] == s[r])
                    l--, r++;
                else
                    break;
            }
            if (r - l - 1 > mx){
                mx = r - l - 1;
                ans = s.substr(l + 1, r - l - 1);
            }
        }
        return ans;
        
    }
};

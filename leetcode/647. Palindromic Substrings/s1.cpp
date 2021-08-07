// OJ: https://leetcode.com/problems/palindromic-substrings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/palindromic-substrings/discuss/105691/JavaC%2B%2B-6-lines-solution-NO-DP
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0, n = s.size();
        
        for (int i = 0; i < n; i++){
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j] == s[i+j]; j++)
                ans++;
            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++)
                ans++;
        }
        return ans;
    }
};

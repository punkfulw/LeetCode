// OJ: https://leetcode.com/problems/license-key-formatting/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        
        for (int i = s.size() - 1, cnt = 0; i >= 0; i--){
            if (s[i] == '-')
                continue;
            ans += toupper(s[i]);
            cnt++;
            if (cnt == k){
                ans += '-';
                cnt = 0;
            }
        }
        
        if (ans.back() == '-')
            ans.pop_back();
        
        return string(ans.rbegin(), ans.rend());
    }
};

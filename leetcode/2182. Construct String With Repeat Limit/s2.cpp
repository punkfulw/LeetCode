// OJ: https://leetcode.com/problems/construct-string-with-repeat-limit/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/2182.%20Construct%20String%20With%20Repeat%20Limit/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int cnt[26] = {};
        
        for (auto c: s)
            cnt[c - 'a']++;
        string ans = "";
        
        while (true){
            int i = 25, onlyOne = 0;
            
            for (; i >= 0; i--){
                if (ans.size() && ans.back() == i + 'a' && cnt[i]){
                    onlyOne = 1;
                    continue;
                }
                if (cnt[i])
                    break;
            }
            if (i == -1)
                break;
            int mn = onlyOne ? 1 : min(repeatLimit, cnt[i]);
            ans += string(mn, (i + 'a'));
            cnt[i] -= mn;
        }
        return ans;
    }
};

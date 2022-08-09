// OJ: https://leetcode.com/problems/get-equal-substrings-within-budget/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int ans = 0, cnt = maxCost;
        for (int p = 0, i = 0; i < s.size(); i++){
            int dif = abs(s[i] - t[i]);
            if (dif > maxCost){
                p = i + 1;
                cnt = maxCost;
                continue;
            }
            while (dif > cnt){
                cnt += abs(s[p] - t[p]);
                p++;
            }
            cnt -= dif;
            ans = max(ans, i - p + 1);
        }
        return ans;
    }
};

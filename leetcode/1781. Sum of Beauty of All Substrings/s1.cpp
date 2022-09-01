// OJ: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    int beautySum(string s) {
        int n = s.size(), ans = 0;
        for (int i = 0; i < n - 2; i++){
            int cnt[26] = {};
            for (int j = i; j < n; j++){
                cnt[s[j] - 'a']++;
                int mx = 0, mn = 500;
                for (int k = 0; k < 26; k++){
                    mx = max(mx, cnt[k]);
                    if (cnt[k])
                        mn = min(mn, cnt[k]);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/discuss/1499860/Prefix-and-Suffix-Counts
// Time: O(N) 
// Space: O(N) 
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int n = nums.size(), ans = 0, tar = target.size();
        int pre[101] = {}, suf[101] = {};
        for (auto s: nums){
            int sz = s.size();
            if (sz >= tar)
                continue;
            bool isPre = s == target.substr(0, sz), isSuf = s == target.substr(tar - sz);
            ans += isPre ? suf[sz] : 0;
            ans += isSuf ? pre[tar - sz] : 0;
            suf[tar - sz] += isSuf;
            pre[sz] += isPre;
        }
        return ans;
    }
};

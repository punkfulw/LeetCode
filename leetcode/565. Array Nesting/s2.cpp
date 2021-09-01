// OJ: https://leetcode.com/problems/array-nesting/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/array-nesting/discuss/102473/JavaC%2B%2BPython-Straight-Forward
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 1, n = nums.size();
        vector<bool> seen(n);
        for (int i: nums){
            int cur = 0;
            while (!seen[i]){
                cur++;
                seen[i] = 1;
                i = nums[i];
            }
            ans = max(ans, cur);
        }
        return ans;
    }
};

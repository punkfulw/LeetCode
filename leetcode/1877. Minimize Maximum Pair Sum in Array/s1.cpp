// OJ: https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size()-1;
        for (int i = 0, j = n; i < j; i++, j--){
            int sum = nums[i]+nums[j];
            ans = max(ans, sum);
        }
        return ans;
    }
};

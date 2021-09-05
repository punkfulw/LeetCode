// OJ: https://leetcode.com/problems/count-special-quadruplets/
// Author: github.com/punkfulw
// Time: O(N^4)
// Space: O(1)
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for (int i = 0; i < n-3; i++)
            for (int j = i+1; j < n-2; j++)
                for (int k = j+1; k < n-1; k++){
                    int num = nums[i] + nums[j] + nums[k];
                    ans += count(nums.begin() + k, nums.end(), num);
                }
        return ans;
    }
};

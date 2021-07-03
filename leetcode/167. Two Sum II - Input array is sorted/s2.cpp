// OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (nums[l] + nums[r] != target){
            if (nums[l] + nums[r] > target)
                r--;
            else
                l++;
        }
        return {l+1, r+1};
    }
};

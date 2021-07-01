// OJ: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int pre = nums[0];
        bool used = false;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] <= pre){
                if (used)
                    return false;
                used = true;
                if (i == 1 || nums[i] > nums[i-2])
                    pre = nums[i];
            }
            else
                pre = nums[i];
        }
        return true;
    }
};

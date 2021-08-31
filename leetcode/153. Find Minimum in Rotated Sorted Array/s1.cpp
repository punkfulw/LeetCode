// OJ: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            if (nums[r] > nums[l])
                return nums[l];
            int m = (l + r) / 2;
            if (nums[m] > nums[r]) l = m + 1;
            else r = m;
        }
        return nums[l];
    }
};

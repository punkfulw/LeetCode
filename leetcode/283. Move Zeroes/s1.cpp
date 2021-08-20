// OJ: https://leetcode.com/problems/move-zeroes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0, j = 0; i < nums.size(); i++, j++){
            while (i < nums.size() && nums[i] == 0)
                i++;
            if (i >= nums.size())
                break;
            swap(nums[i], nums[j]);
        }
        return;
    }
};

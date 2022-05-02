// OJ: https://leetcode.com/problems/sort-array-by-parity/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = 0, n = nums.size();
        
        for (int i = 0, j = 0; j < n; j++)
            if (nums[j] % 2 == 0)
                swap(nums[i++], nums[j]);
        return nums;
    }
};

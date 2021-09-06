// OJ: https://leetcode.com/problems/find-the-middle-index-in-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int left = 0, right = accumulate(nums.begin(), nums.end(), 0);
        for (int i = 0; i < nums.size(); i++){
            right -= nums[i];
            if (right == left)
                return i;
            left += nums[i];
        }
        return -1;
    }
};

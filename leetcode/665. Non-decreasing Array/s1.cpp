// OJ: https://leetcode.com/problems/non-decreasing-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), times = 0;
        for (int i = 0; i < n - 1; i++){
            if (nums[i] <= nums[i + 1]) continue;
            if (times > 0) return false;
            times++;
            if (i == 0) continue;
            if (nums[i + 1] < nums[i - 1]) nums[i + 1] = nums[i];
        }
        return true;
    }
};



// OJ: https://leetcode.com/problems/decrease-elements-to-make-array-zigzag/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int sol(vector<int> nums, int start){
        int cnt = 0, n = nums.size();
        for (int i = start; i < n; i += 2){
            if (i > 0 && nums[i] <= nums[i - 1])
                cnt += (nums[i - 1] - nums[i] + 1);
            if (i < n - 1 && nums[i] <= nums[i + 1]){
                cnt += (nums[i + 1] - nums[i] + 1);
                nums[i + 1] = nums[i] - 1;
            }
        }
        return cnt;
    }
    int movesToMakeZigzag(vector<int>& nums) {
        return min(sol(nums, 0), sol(nums, 1));
    }
};

// OJ: https://leetcode.com/problems/jump-game/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        for (int i = 0, power = nums[0]; i < nums.size() - 1; i++){
            power = max(power, nums[i]);
            power--;
            if (power < 0)
                return false;
        }
        return true;
    }
};

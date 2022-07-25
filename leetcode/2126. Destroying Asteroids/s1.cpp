// OJ: https://leetcode.com/problems/destroying-asteroids/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    bool asteroidsDestroyed(long mass, vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (mass >= nums[i])
                mass += nums[i];
            else
                return false;
        }
        return true;
    }
};

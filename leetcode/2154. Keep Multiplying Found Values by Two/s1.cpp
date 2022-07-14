// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == ori)
                ori *= 2;
        }
        return ori;
    }
};

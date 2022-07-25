// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = lower_bound(nums.begin(), nums.end(), target), it2 = upper_bound(nums.begin(), nums.end(), target);
        if (it1 == nums.end() || *it1 != target)
            return {-1, -1};
        return {int(it1 - nums.begin()), int(it2 - nums.begin()) - 1};
    }
};

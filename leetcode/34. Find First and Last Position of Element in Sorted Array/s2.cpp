// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/discuss/14717/C%2B%2B-binary-search-solution-(lower_bound-implementation).
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int idx1 = lower_bound(nums, target);
        int idx2 = lower_bound(nums, target + 1) - 1;
        if (idx1 < nums.size() && nums[idx1] == target)
            return {idx1, idx2};
        else
            return {-1, -1};
    }

    int lower_bound(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (r - l) / 2 + l;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l;
    }
};

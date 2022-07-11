// OJ: https://leetcode.com/problems/find-peak-element/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r){
            int m = (l + r) / 2;
            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;
        }
        return l;
    }
};

// OJ: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans (2, -1);
        auto it = find(nums.begin(), nums.end(), target);
        
        if (it != nums.end()){
             auto it2 = find(nums.rbegin(), nums.rend(), target);
             ans[0] = it - nums.begin();
             ans[1] = nums.size() - (it2 - nums.rbegin()) - 1;
         }
        return ans;
    }
};

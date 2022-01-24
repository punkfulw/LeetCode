// OJ: https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int countElements(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        sort(nums.begin(), nums.end());
        
        if (n == 1 || nums[l] == nums[r])
            return 0;
        while (nums[l+1] == nums[l])
            l++;
        while (nums[r-1] == nums[r])
            r--;
        return max(0, r - l - 1);
    }
};

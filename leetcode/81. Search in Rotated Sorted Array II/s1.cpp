// OJ: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Author: github.com/punkfulw
// Time: average O(logN), worst O(N)
// Space: O(1)
class Solution {
public:
    bool findT(vector<int>& nums, int l, int r, int target)
    {
        while (l <= r)
            if (nums[l++] == target)
                return true;
        return false;
    }
    
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r && nums[l] != nums[r])
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return true;

            if (nums[mid] < target)
            {
                if (nums[mid] >= nums[l] || nums[l] > target)
                    l = mid + 1; 
                else
                    r = mid - 1;    
            }
            else
            {
                if (nums[l] > nums[mid] || nums[l] <= target)
                    r = mid - 1;
                else
                    l = mid + 1;
            }     
            
        }
        return findT(nums, l, r, target);
    }
};

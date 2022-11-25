// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), low = 0, mid = 0, high = n - 1;
        
        while (mid <= high){
            if (nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else if (nums[mid] == 1)
                mid++;
            else 
                swap(nums[mid], nums[high--]);
        }
    }
};

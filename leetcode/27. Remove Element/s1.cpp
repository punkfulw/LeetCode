// OJ: https://leetcode.com/problems/remove-element/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(), i = 0;
        for (int j = n-1; i <= j;){
            if (nums[i] == val)
                swap(nums[i], nums[j--]);
            else
                i++;
        }
        return i;
    }
};

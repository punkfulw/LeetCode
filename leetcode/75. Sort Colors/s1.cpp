// OJ: https://leetcode.com/problems/sort-colors/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int zero {};
        int one {};
        
        for (int i = 0; i < size; i++){
            if(nums[i] == 0)
                zero++;
            else if (nums[i] == 1)
                one++;
        }
        for (int i = 0; i < zero; i++){
            nums[i] = 0;
        }
        for (int i = 0; i < one; i++){
            nums[i+zero] = 1;
        }
        for (int i = 0; i < size-one-zero; i++){
            nums[i+zero+one] = 2;
        }
    }
};

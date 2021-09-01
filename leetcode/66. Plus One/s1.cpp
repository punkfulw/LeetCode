// OJ: https://leetcode.com/problems/plus-one/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> plusOne(vector<int>& nums) {
        for (int i = nums.size()-1; i >= 0; i--){
            nums[i]++;
            if (nums[i] < 10)
                break;
            nums[i] = 0;
        }
        if (nums[0] == 0)
            nums.insert(nums.begin(), 1);
        
        return nums;
    }
};

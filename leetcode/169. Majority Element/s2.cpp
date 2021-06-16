// OJ: https://leetcode.com/problems/majority-element/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        for (int i = 1, count = 1; i < nums.size(); i++){
            nums[majorityIndex] == nums[i] ? count++ : count--;
            if (count == 0){
                majorityIndex = i;
                count = 1;
            }
        }
        return nums[majorityIndex];
    }
};

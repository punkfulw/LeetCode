// OJ: https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        int ans {};
        
        for (int i = 1; i < size; i++){
            if (nums[i] <= max){
                ans += max - nums[i] + 1;
                max++;
            }
            else
                max = nums[i];
        }
        return ans;
    }
};

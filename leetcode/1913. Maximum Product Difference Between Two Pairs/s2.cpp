// OJ: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] <= min2){
                if (nums[i] <= min1){
                    min2 = min1;
                    min1 = nums[i];
                }
                else
                    min2 = nums[i];
            }
            if (nums[i] >= max2){
                if (nums[i] >= max1){
                    max2 = max1;
                    max1 = nums[i];
                }
                else
                    max2 = nums[i];
            }
        }
        return max1 * max2 - min1 * min2;
    }
};



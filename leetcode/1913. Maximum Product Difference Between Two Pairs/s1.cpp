// OJ: https://leetcode.com/problems/maximum-product-difference-between-two-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1, max2;
        int min1, min2;
        max1 = *max_element(nums.begin(), nums.end());
        nums.erase(max_element(nums.begin(), nums.end()));
        max2 = *max_element(nums.begin(), nums.end());
        nums.erase(max_element(nums.begin(), nums.end()));
        min1 = *min_element(nums.begin(), nums.end());
        nums.erase(min_element(nums.begin(), nums.end()));
        min2 = *min_element(nums.begin(), nums.end());
        nums.erase(min_element(nums.begin(), nums.end()));
        
        return max1 * max2 - min1 * min2;
    }
};

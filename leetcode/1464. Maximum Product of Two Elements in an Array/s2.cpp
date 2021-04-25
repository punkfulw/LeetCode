// OJ: https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int f_max {};
        int s_max {};
        
        for (auto num: nums){
            if (num >= f_max){
                s_max = f_max;
                f_max = num;
            }
            else if (num > s_max)
                s_max = num;
        }
        return (s_max - 1) * (f_max - 1);
        
    }
};

// OJ: https://leetcode.com/problems/minimum-value-to-get-positive-step-by-step-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0, small = 0; 
        for (int i: nums){
            sum += i;
            small = min(small, sum);
        }
        return small >= 0 ? 1 : 1 - small; 
    }
};

// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0), ttl = (n + 1) * n / 2;
        return ttl - sum;  
    }
};

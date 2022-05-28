// OJ: https://leetcode.com/problems/missing-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, ans = nums.size();
        
        for (auto num: nums){
            ans ^= i++;
            ans ^= num;
        }
        return ans;
    }
};

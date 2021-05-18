// OJ: https://leetcode.com/problems/squares-of-a-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size()-1;
        int i = 0;
        vector<int> ans (n+1);
        for  (int j = n; j >= 0; j--){
            if (abs(nums[i]) > abs(nums[n]))
                ans[j] = nums[i] * nums[i++];
            else 
                ans[j] = nums[n] * nums[n--];
        }
        return ans;
    }
};

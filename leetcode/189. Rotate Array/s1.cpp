// OJ: https://leetcode.com/problems/rotate-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++){
            ans[(i+k) % n] = nums[i];
        }
        nums = ans;
        return;
    }
};

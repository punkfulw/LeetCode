// OJ: https://leetcode.com/problems/next-greater-element-ii/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, INT_MIN);
        for (int i = 0; i < n; i++){
            for (int j = 1; j < n; j++)
                if (nums[(i + j) % n] > nums[i]){
                    ans[i] = nums[(i + j) % n];
                    break;
                }
            if (ans[i] == INT_MIN)
                ans[i] = -1;
        }
        return ans;
    }
};

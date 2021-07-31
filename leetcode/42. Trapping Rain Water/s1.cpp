// OJ: https://leetcode.com/problems/trapping-rain-water/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/42.%20Trapping%20Rain%20Water/README.md
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), ans = 0;
        vector<int> left(n), right(n);
        for (int i = 1; i < n; i++)
            left[i] = max(left[i-1], height[i-1]);
        for (int i = n-2; i >= 0; i--)
            right[i] = max(right[i+1], height[i+1]);
        for (int i = 1; i < n-1; i++)
            ans += max(0, min(left[i], right[i]) - height[i]);
        return ans;    
    }
};

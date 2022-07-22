// OJ: https://leetcode.com/problems/removing-minimum-and-maximum-from-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;
        auto itmn = min_element(nums.begin(), nums.end());
        auto itmx = max_element(nums.begin(), nums.end());
        int mn_front = itmn - nums.begin() + 1, mn_back = nums.end() - itmn;
        int mx_front = itmx - nums.begin() + 1, mx_back = nums.end() - itmx;
        
        return min({max(mn_front, mx_front), max(mn_back, mx_back), mn_front + mx_back, mx_front + mn_back});
    }
};

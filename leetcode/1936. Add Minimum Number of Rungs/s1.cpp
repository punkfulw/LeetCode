// OJ: https://leetcode.com/problems/add-minimum-number-of-rungs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int addRungs(vector<int>& nums, int dist) {
        int cnt = 0;
        int n = nums.size();
        int pos = 0;
        
        for (int i = 0; i < n; i++){
            if (pos + dist < nums[i])
                cnt = cnt + (nums[i] - pos - 1) / dist;
            pos = nums[i];
        }
        return cnt;
    }
};

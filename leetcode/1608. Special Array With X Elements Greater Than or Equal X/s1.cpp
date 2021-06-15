// OJ: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int cnt[1001] = {};
        for (int i: nums) cnt[i]++;
        int m = n;
        
        for (int i = 0; i <= n; i++){
            if (i == m) return i;
            m -= cnt[i];
        }
        return -1;
    }
};

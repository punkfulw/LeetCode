// OJ: https://leetcode.com/problems/ways-to-make-a-fair-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int cnt = 0, n = nums.size();
        vector<int> LtoR = nums, RtoL = nums;
        for (int i = 2; i < n; i++){
            LtoR[i] += LtoR[i - 2];
            RtoL[n-1-i] += RtoL[n-1-i+2];
        }
        
        for (int i = 0; i < n; i++){
            int r = 0, l = 0;
            if (i >= 1)
                l += LtoR[i-1];
            if (i < n - 2)
                l += RtoL[i+2];
            if (i >= 2)
                r += LtoR[i-2];
            if (i < n - 1)
                r += RtoL[i+1];
            if (l == r)
                cnt++;
        }
        return cnt;
    }
};

// OJ: https://leetcode.com/problems/max-consecutive-ones/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0, cnt = 0;
        for (int i: nums){
            if (i == 1)
                cnt++;
            else
                cnt = 0;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

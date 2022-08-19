// OJ: https://leetcode.com/problems/find-closest-number-to-zero/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans, dif = INT_MAX / 2;
        for (int i: nums){
            int cur = abs(i);
            if (cur < dif){
                ans = i;
                dif = cur;
            }
            else if (cur == dif && i > ans)
                ans = i;
        }
        return ans;
    }
};

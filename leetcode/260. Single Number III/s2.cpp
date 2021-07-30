// OJ: https://leetcode.com/problems/single-number-iii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/single-number-iii/discuss/68900/Accepted-C%2B%2BJava-O(n)-time-O(1)-space-Easy-Solution-with-Detail-Explanations
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long dif = 0;
        for (int num: nums) dif ^= num;
        dif &= -dif; 
        
        vector<int> ans(2, 0);
        for (int num: nums)
            ans[!(num & dif)] ^= num;
        return ans;
    }
};

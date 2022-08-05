// OJ: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0ll;
        for (int i = 0; i <= total / cost1; i++){
            int remain = total - i * cost1;
            ans += (remain / cost2 + 1);
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/time-needed-to-buy-tickets/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int tar = tickets[k], n = tickets.size(), ans = 0;
        for (int i = 0; i < n; i++){
            int t = tickets[i];
            if (i <= k)
                ans += min(t, tar);
            else
                ans += min(t, tar - 1);
        } 
        return ans;
    }
};

// OJ: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans = 0, n = p.size();
        int pre = p[0];
        for (int i = 0; i < n - 1;){
            while (i+1 < n && p[i+1] >= p[i])
                i++;
            ans += p[i] - pre;
            cout << pre << " " << p[i] << endl;
            pre = p[++i];
        }
        return ans;
    }
};

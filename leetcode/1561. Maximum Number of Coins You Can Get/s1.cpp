// OJ: https://leetcode.com/problems/maximum-number-of-coins-you-can-get/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        int ans = 0;
        sort(piles.begin(), piles.end());
        int pos = n-2;
        for (int i = 0; i < n / 3; i++){
            ans += piles[pos];
            pos -= 2;
        }
        return ans;
    }
};

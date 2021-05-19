// OJ: https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int cnt[2] = {};
        for (int i: position){
            if (i % 2)
                cnt[0]++;
            else
                cnt[1]++;
        }
        return min(cnt[0], cnt[1]);
    }
};

// OJ: https://leetcode.com/problems/number-of-equivalent-domino-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dom) {
        int n = dom.size(), ans = 0, type[10][10] = {};
        for (auto d: dom){
            if (d[0] > d[1])
                swap(d[0], d[1]);
            type[d[0]][d[1]]++;
        }
        
        for (int i = 1; i < 10; i++){
            for (int j = 1; j < 10; j++){
                int num = type[i][j];
                ans += (num - 1) * num / 2;
            }
        }
        return ans;
    }
};

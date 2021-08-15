// OJ: https://leetcode.com/problems/maximal-network-rank/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> connect(n, vector<int> (n));
        vector<int> rank(n);
        for (auto road: roads){
            int i = road[0], j = road[1];
            rank[i]++;
            rank[j]++;
            connect[i][j] = connect[j][i] = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                int cur = rank[i] + rank[j];
                if (connect[i][j] || connect[j][i])
                    cur--;
                ans = max(ans, cur);
            }
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/
// Author: github.com/lzl124631x
// Time: O(PC)
// Space: O(1)
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& P, vector<vector<int>>& C) {
        vector<int> ans {};
        int n = C.size(), m = P.size();
        
        for (int i = 0; i < n; i++){
            int cnt = 0;
            for (int j = 0; j < m; j++){
                double dis = pow(pow(abs(C[i][0] - P[j][0]), 2) + pow(abs(C[i][1] - P[j][1]), 2), 0.5);
                if (dis <= C[i][2])
                    cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/queue-reconstruction-by-height
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& P) {
        int n = P.size();      
        sort(P.begin(), P.end());
        vector<vector<int>> ans(n, vector<int> (2, -1));
        for (auto p: P){
            int skip = p[1], pos = 0;
            while (ans[pos][0] != -1){
                skip -= ans[pos][0] == p[0] ? 1 : 0;
                pos++;
            }
            while (skip > 0){
                if (ans[pos][0] == -1 || ans[pos][0] == p[0])
                    skip--; 
                pos++;
            }
            while (ans[pos][0] != -1)
                pos++;
            ans[pos] = p;
        }
        return ans;
    }
};



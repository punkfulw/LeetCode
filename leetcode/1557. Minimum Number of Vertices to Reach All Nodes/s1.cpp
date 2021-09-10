// OJ: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> seen(n);
        for (auto e: edges)
            seen[e[1]] = true;
        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!seen[i])
                ans.push_back(i);
        return ans;
                
    }
};

// OJ: https://leetcode.com/problems/redundant-connection/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/redundant-connection/discuss/108010/C%2B%2B-solution-using-union-find
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1, 0);
        for (auto &e: edges) {
            int v1 = e[0], v2 = e[1];
            while (parent[v1]) v1 = parent[v1];
            while (parent[v2]) v2 = parent[v2];
            if (v1 == v2) return e;
            parent[v1] = v2;
        }
        return {};
    }
};

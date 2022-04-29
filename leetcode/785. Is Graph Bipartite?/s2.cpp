// OJ: https://leetcode.com/problems/is-graph-bipartite/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/785.%20Is%20Graph%20Bipartite%3F/README.md
// Time: O(V + E)
// Space: O(V + E)
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &id, int i, int prev = 1)
    {
        if (id[i])
            return id[i] != prev;
        id[i] = -prev;
        for (auto child: graph[i])
            if (dfs(graph, id, child, -prev) == false)
                return false;
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> id(n);
        for (int i = 0; i < n; i++)
            if (!id[i] && dfs(graph, id, i) == false)
                return false;
        return true;
    }
};

// OJ: https://leetcode.com/problems/all-paths-from-source-to-target/
// Author: github.com/punkfulw
// Time: O(N * 2^N)
// Space: O(N) 
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, vector<int> &p, vector<vector<int>>& graph){
        p.push_back(i);
        if (i == graph.size() - 1)
            ans.push_back(p);
        else
            for (auto nxt: graph[i])
                dfs(nxt, p, graph);   
        p.pop_back();
        return;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> p;
        dfs(0, p, graph);
        return ans;
    }
};

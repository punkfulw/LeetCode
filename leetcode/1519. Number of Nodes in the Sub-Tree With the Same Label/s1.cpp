// OJ: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> graph;
    vector<int> ans;
    
    vector<int> dfs(int node, string &labels, int pre){
        char c = labels[node];
        vector<int> cnt(26);
        cnt[c - 'a']++;
        
        for (auto nxt: graph[node]){
            if (nxt == pre)
                continue;
            vector<int> child = dfs(nxt, labels, node);
            for (int i = 0; i < 26; i++)
                cnt[i] += child[i];
        }
        ans[node] = cnt[c - 'a'];
        return cnt;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        graph.resize(n);
        ans.resize(n);
        
        for (auto e: edges){
            int a = e[0], b = e[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        dfs(0, labels, -1);
        return ans;
    }
};

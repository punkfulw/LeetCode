// OJ: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/discuss/806267/Union-find-straightforward-C%2B%2B
// Time: O(N)
// Space: O(N)
class Solution {
public:    
    vector<int> parent;
    
    int findp(int num){
        if (parent[num] == -1) return num;
        return findp(parent[num]);
    }
    
    void union1(int u, int v){
        int pu = findp(u);
        int pv = findp(v);
        parent[v] = u;
    }
        
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        parent = vector<int> (n, -1);
        for (auto e: edges)
            union1(e[0], e[1]);
        vector<int> ans;
        for(int i = 0; i < n; i++)
            if (parent[i] == -1)
                ans.push_back(i);
        return ans;
    }
};

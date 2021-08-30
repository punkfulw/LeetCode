// OJ: https://leetcode.com/problems/find-if-path-exists-in-graph/
// Author: github.com/punkfulw
// Time: O(ElogV)
// Space: O(logV)
class Solution {
public:
    vector<int> p;
    int findP(int node){
        return p[node] == -1 ? node : p[node] = findP(p[node]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        p.resize(n, -1);
        for (auto edge: edges){
            int pu = findP(edge[0]), pv = findP(edge[1]);
            if (pu != pv)
                p[pu] = pv;
        }
        return findP(start) == findP(end);
    }
};

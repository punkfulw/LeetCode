// OJ: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
// Author: github.com/punkfulw
// Time: O(E * logN)
// Space: O(N)
class Solution {
public:
    vector<int> par;
    
    int find(int x){
        if (par[x] == x)
            return x;
        par[x] = find(par[x]);
        return par[x];
    }
    
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if (a < b)
            par[b] = a;
        else
            par[a] = b;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        par.resize(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
            par[i] = i;
        
        for (auto c: connections){
            int a = c[0], b = c[1];
            if (find(a) == find(b))
                cnt++;                
            Union(a, b);
        }
        
        unordered_set<int> group;
        for (int i = 0; i < n; i++)
            group.insert(find(i));
        
        int g = group.size(), move = g - 1;
        if (g == 1)
            return 0;
        if (cnt >= move)
            return move;
        return -1;
    }
};

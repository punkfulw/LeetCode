// OJ: https://leetcode.com/problems/satisfiability-of-equality-equations/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int parent[26] = {};
    
    int find(int a){
        return parent[a] == a ? a : parent[a] = find(parent[a]); 
    }
    
    void unionNode(char a, char b){
        int p1 = find(a - 'a'),  p2 = find(b - 'a');
        if (p1 != p2)
            parent[p1] = p2;
    }
    
    bool equationsPossible(vector<string>& eq) {
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        
        for (auto e: eq)
            if (e[1] == '=')
                unionNode(e[0], e[3]);

        for (auto e: eq)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }
};

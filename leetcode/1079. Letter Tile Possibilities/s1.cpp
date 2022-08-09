// OJ: https://leetcode.com/problems/letter-tile-possibilities/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int n;
    unordered_set<string> ans;
    
    void dfs(int i, string &s, string &tiles, vector<int> &visited){
        s += tiles[i];
        visited[i] = 1;
        ans.insert(s);
        for (int j = 0; j < n; j++)
            if (!visited[j])
                dfs(j, s, tiles, visited);
        visited[i] = 0;
        s.pop_back();
    }
    
    int numTilePossibilities(string tiles) {
        n = tiles.size();
        sort(tiles.begin(), tiles.end());
        for (int i = 0; i < n; i++){
            string s;
            if (i == 0 || tiles[i] != tiles[i - 1]){
                vector<int> visited(n);
                dfs(i, s, tiles, visited);
            }
        }
        return ans.size();
    }
};

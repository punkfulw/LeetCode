// OJ: https://leetcode.com/problems/freedom-trail/
// Author: github.com/punkfulw
// Time: O(NM)
// Space: O(NM)
class Solution {
public:
    int n, m;
    vector<vector<int>> dp; 
    int sol(int pos, int j, string &ring, string &key){
        if (j == m)
            return 0;
        if (dp[pos][j] != -1)
            return dp[pos][j];
        int l = pos, r = pos, mn = INT_MAX, l_move = 0, r_move = 0;
        while (ring[l] != key[j]){
            l = (l - 1 + n) % n;
            l_move++;
        }
        while (ring[r] != key[j]){
            r = (r + 1 + n) % n;
            r_move++;
        }
        
        mn = min(l_move + sol(l, j + 1, ring, key), r_move + sol(r, j + 1, ring, key));
        return dp[pos][j] = mn;
    }
    
    int findRotateSteps(string ring, string key) {
        n = ring.size(), m = key.size();
        dp.resize(n, vector<int> (m, -1));
        
        return sol(0, 0, ring, key) + m;
    }
};

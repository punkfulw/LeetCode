// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(M+N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> prerow (m, 1), precol (n, 1);
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                precol[j] += prerow[i] ;
                prerow[i] = precol[j];
            }
        }
        return precol[n-1];
    }
};

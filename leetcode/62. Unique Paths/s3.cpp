// OJ: https://leetcode.com/problems/unique-paths/
// Author: github.com/punkfulw
// Time: O(MN)
// Space: O(N)
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> precol (n, 1);
        
        for (int i = 1; i < m; i++){
            int cur = 1;
            for (int j = 1; j < n; j++){
                precol[j] += cur;
                cur = precol[j];
            }
        }
        return precol[n-1];
    }
};

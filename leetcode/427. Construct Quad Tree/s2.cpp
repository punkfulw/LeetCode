// OJ: https://leetcode.com/problems/construct-quad-tree/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/427.%20Construct%20Quad%20Tree/README.md
// Time: O(N^2 + log_4^N * N)
// Space: O(N^2)
class Solution {
public:
    vector<vector<int>> prefix;
    
    Node* dfs(int x, int y, int N){
        int sum = prefix[x + N][y + N] - prefix[x][y + N] - prefix[x + N][y] + prefix[x][y];
        if (sum == N * N || sum == 0)
            return new Node(sum, 1);
        return new Node(true, false,
                        dfs(x, y, N / 2),
                        dfs(x, y + N / 2, N / 2),
                        dfs(x + N / 2, y, N / 2),
                        dfs(x + N / 2, y + N / 2, N / 2));
    }
    
    Node* construct(vector<vector<int>>& nums) {
        int n = nums.size();    
        prefix.resize(n + 1, vector<int> (n + 1));
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 1; j <= n; j++){
                sum += nums[i - 1][j - 1];
                prefix[i][j] = sum + prefix[i - 1][j];
            }
        }
        
        return dfs(0, 0, n);
        
    }
};

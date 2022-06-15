// OJ: https://leetcode.com/problems/maximum-points-in-an-archery-competition/
// Author: github.com/punkfulw
// Time: O(2^12 * 12)
// Space: O(2^12 * 12)
class Solution {
public:
    int mx = 0;
    vector<int> ans;
    void dfs(int i, int n, int cnt, vector<int>& A, vector<int>& cur){
        if (i == 12){
            if (cnt > mx){
                mx = cnt;
                cur[0] = n;
                ans = cur;
            }
            return;
        }
        if (n > A[i]){
            cur[i] = A[i] + 1;
            dfs(i + 1, n - A[i] - 1, cnt + i, A, cur);
            cur[i] = 0;
        }
        dfs(i + 1, n, cnt, A, cur);
    }
    
    vector<int> maximumBobPoints(int n, vector<int>& A) {
        vector<int> cur(12);
        dfs(1, n, 0, A, cur);
        
        return ans;
    }
};

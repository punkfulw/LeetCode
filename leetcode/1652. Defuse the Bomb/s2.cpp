// OJ: https://leetcode.com/problems/defuse-the-bomb/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if (k == 0)
            return ans;
        int sum = 0, start = 1, end = k;
        
        if (k < 0){
            start = n+k;
            end = n-1;
        }
        for (int i = start; i <= end; i++)
            sum += code[i];
        for (int i = 0; i < n; i++){
            ans[i] = sum;
            sum = sum - code[(start++) % n] + code[(++end) % n];
        }
        return ans;
    }
};

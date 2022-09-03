// OJ: https://leetcode.com/problems/numbers-with-same-consecutive-differences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int n, k;
    vector<int> ans;
        
    void dfs(int num, int pre, int sz){
        if (sz == n){
            ans.push_back(num);
            return;
        }
        for (int d = 0; d < 10; d++)
            if (abs(d - pre) == k)
                dfs(num * 10 + d, d, sz + 1);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        this->n = n;
        this->k = k;
        
        for (int i = 1; i < 10; i++)
            dfs(i, i, 1);
        
        return ans;
    }
};

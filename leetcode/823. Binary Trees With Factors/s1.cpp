// OJ: https://leetcode.com/problems/binary-trees-with-factors/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    long MOD = 1e9 + 7, ans = 0;
    unordered_map<int, int> cnt, dp;
    long dfs(int cur, vector<int>& arr){
        if (dp[cur])
            return dp[cur];
        long ret = 1;
        for (int j = 0; arr[j] < cur; j++){
            int l = arr[j], r = cur / arr[j];
            if (cur % l == 0 && cnt[r])
                ret = (ret + dfs(l, arr) * dfs(r, arr) % MOD) % MOD;
        }
        return dp[cur] = ret;
    }
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        for (auto i: arr)
            cnt[i]++;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++){
            ans = ans + dfs(arr[i], arr) % MOD;
        }
        return ans % MOD;
    }
};

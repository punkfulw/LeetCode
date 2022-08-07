// OJ: https://leetcode.com/problems/count-vowels-permutation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> dp;
    int n, MOD = 1e9 + 7;
    char vowel[6] = {'a', 'e', 'i', 'o', 'u'};
    
    int dfs(int i, char v){
        int c = v == 'a' ? 0 : v == 'e' ? 1 : v == 'i' ? 2 : v == 'o' ? 3 : 4;
        if (i == n)
            return 1;
        if (dp[i][c])
            return dp[i][c];
        int cnt = 0;
        switch(v){
            case '0':
                for (int j = 0; j < 5; j++)
                    cnt = (cnt + dfs(i + 1, vowel[j])) % MOD;
                break;
            case 'a':
                cnt = (cnt + dfs(i + 1, 'e')) % MOD;
                break;
            case 'e':
                cnt = (cnt + dfs(i + 1, 'a')) % MOD;
                cnt = (cnt + dfs(i + 1, 'i')) % MOD;
                break;
            case 'i':
                for (int j = 0; j < 5; j++)
                    if (j != 2)
                        cnt = (cnt + dfs(i + 1, vowel[j])) % MOD;
                break;
            case 'o':
                cnt = (cnt + dfs(i + 1, 'i')) % MOD;
                cnt = (cnt + dfs(i + 1, 'u')) % MOD;
                break;
            case 'u':
                cnt = (cnt + dfs(i + 1, 'a')) % MOD;
                break;   
        }
        return dp[i][c] = cnt;
    }
    int countVowelPermutation(int n) {
        this->n = n;
        dp.resize(n + 1, vector<int>(5));
        return dfs(0, '0');
    }
};

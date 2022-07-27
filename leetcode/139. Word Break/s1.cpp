// OJ: https://leetcode.com/problems/word-break/
// Author: github.com/punkfulw
// Time: O(S^3)
// Space: O(S + W)
class Solution {
public:
    int n;
    vector<int> dp;
    bool sol(string s, set<string> &st, int i){
        if (i == n)
            return true;
        if (dp[i] != -1)
            return dp[i];
        bool ret = 0;
        for (int j = n - i; j >= 0 && !ret; j--){
            string cur = s.substr(i, j);
            if (st.find(cur) != st.end())
                ret |= sol(s, st, i + j);
        }
        return dp[i] = ret;
    }
    
    bool wordBreak(string s, vector<string>& dic) {
        n = s.size();
        dp.resize(n, -1);
        set<string> st(dic.begin(), dic.end());
        return sol(s, st, 0);
    }
};

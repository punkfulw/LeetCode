// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_set<string> ans;    
    void dfs(string s, int l, int r, int n, int cnt){
        if (l == n && r == n && cnt == 0){
            ans.insert(s);
            return;
        }
        if (cnt < 0 || l > n || r > n)
            return;
        dfs(s + "(", l + 1, r, n, cnt + 1);
        dfs(s + ")", l, r + 1, n, cnt - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        
        dfs("", 0, 0, n, 0);
        
        return vector<string>(ans.begin(), ans.end());
    }
};

// OJ: https://leetcode.com/problems/generate-parentheses/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/generate-parentheses/discuss/10105/Concise-recursive-C%2B%2B-solution
// Time: O(N)
// Space: O(N)
class Solution {
    void dfs(vector<string>& ans, string& str, int left, int right){
        if (left == 0 && right == 0){
            ans.push_back(str);
            return;
        }
        if (left > 0){
            str.push_back('(');
            dfs(ans, str, left-1, right);
            str.pop_back();
        }
        if (left < right){
            str.push_back(')');
            dfs(ans, str, left, right-1);
            str.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        dfs(ans, str, n, n);
        return ans;
    }
};

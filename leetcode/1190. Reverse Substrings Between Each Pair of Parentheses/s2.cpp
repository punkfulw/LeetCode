// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public: 
    string reverseParentheses(string s) {
        stack<int> stk;
        string ans;

        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')'){
                int top = stk.top();
                reverse(s.begin() + top, s.begin() + i);
                stk.pop();
            }
        }
        for (auto c: s)
            if (c != '(' && c != ')')
                ans += c;
        return ans;
    }
};

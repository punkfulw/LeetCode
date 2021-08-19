// OJ: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for (auto c: s){
            if (c == '(')
                stk.push(c);
            else{
                if (stk.empty() || stk.top() != '(')
                    stk.push(c);
                else
                    stk.pop();
            }
        }
        return stk.size();
    }
};

// OJ: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        
        for (auto t: tokens){
            if (isdigit(t[t.size()-1]))
                stk.push(stoi(t));
            else {
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                switch (t[0]){
                    case '+': stk.push(a+b); break;
                    case '-': stk.push(a-b); break;
                    case '*': stk.push(a*b); break;
                    case '/': stk.push(a/b); break;
                }
            }
        }
        return stk.top();
    }
};

// OJ: https://leetcode.com/problems/valid-parentheses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> mp = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
        
        for (char c: s){
            if (c == '(' || c == '[' || c == '{')
                stk.push(c);
            else{
                if (stk.empty())
                    return false;
                char pre = stk.top();
                if (c != mp[pre])
                    return false;
                stk.pop();
            }
        }
        if (!empty(stk))
            return false;
        return true;
    }
};

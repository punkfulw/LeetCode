// OJ: https://leetcode.com/problems/decode-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        string ans = "";
        stack<string> stk;
        
        for (int i = 0; i < n; i++){
            if (s[i] == ']'){
                string inside = "", mul;
                while (stk.top() != "["){
                    inside = stk.top() + inside;
                    stk.pop();
                }
                stk.pop();
                mul = stk.top();
                stk.pop();
                string newS = "";
                for (int i = 0; i < stoi(mul); i++)
                    newS += inside;
                stk.push(newS);
            }
            else if (isdigit(s[i])){
                string dig = "";
                while (isdigit(s[i])){
                    dig += s[i++];
                }
                i--;
                stk.push(dig);
            }
            else{
                stk.push(string(1, s[i]));
            }
        }
        
        while (!stk.empty()){
            ans = stk.top() + ans;
            stk.pop();
        }
        
        return ans;
    }
};

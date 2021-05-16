// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string reverseWords(string s) {
        stack<char> stk;
        string ans;
        
        for (auto c: s){
            if (c != ' ')
                stk.push(c);
            else{
                while (!stk.empty()){
                    char l = stk.top();
                    ans.push_back(l);
                    stk.pop();
                }
                ans.push_back(' ');
            }
        }
        while (!stk.empty()){
                    char l = stk.top();
                    ans.push_back(l);
                    stk.pop();
                }
        
        return ans;
    }
};

// OJ: https://leetcode.com/problems/remove-outermost-parentheses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string removeOuterParentheses(string S) {
        string ans;
        int index {};
        
        for (int i = 0; i < S.size(); i++){
            if (S[i] == '('){
                if (index == 0){
                    index++;
                    continue;
                }
                index++;
                ans.push_back(S[i]);
            }
            else {
                index--;
                if (index == 0)
                    continue;
                ans.push_back(S[i]);
            }
        }
        return ans;
    }
};

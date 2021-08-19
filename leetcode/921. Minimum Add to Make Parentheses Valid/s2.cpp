// OJ: https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
// Author: github.com/punkfulw
// Ref: https://github.com/punkfulw/LeetCode-1/edit/master/leetcode/921.%20Minimum%20Add%20to%20Make%20Parentheses%20Valid/README.md
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        int left = 0, invalidright = 0;
        for (auto c: s){
            if (c == '(') left++;
            else{
                if (!left)
                    invalidright++;
                else
                    left--;
            }
        }
        return left + invalidright;
    }
};

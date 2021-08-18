// OJ: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N^2)
class Solution {
public:
    string reverseParentheses(string s) {
        int index = 0;
        return recur(s, index);
    }
    string recur(string s, int& index){
        string ans;
        int n = s.size();
        while (index < n){
            if (s[index] == '('){
                string mid = recur(s, ++index);
                reverse(mid.begin(), mid.end());
                ans += mid;
            }
            else if (s[index] == ')')
                break;
            else
                ans += s[index];
            index++;
        }
        return ans;
    }
};

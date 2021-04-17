// OJ: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxDepth(string s) {
        int max {};
        int count {};
        for (const auto &c: s){
            if(c == '(')
                count++;
            if(count > max)
                max = count;
            if(c == ')')
                count--;
        }
        return max;
    }
};

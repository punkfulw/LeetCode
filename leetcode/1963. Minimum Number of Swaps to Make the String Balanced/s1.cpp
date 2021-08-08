// OJ: https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        stack<char> stk;
        stk.push(s[0]);
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '[')
                stk.push(s[i]);
            else {
                if (stk.empty())
                    stk.push(s[i]);
                if (stk.top() == '[')
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        cnt = stk.size()/2;
        return (cnt+1)/2;
    }
};

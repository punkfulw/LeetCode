// OJ: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = 0;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '0')
                flag = 1;
            else
                if (flag)
                    return 0;
        }
        return 1;
    }
};

// OJ: https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(string s) {
        int d1 = 0, d2 = 0;
        for (int i = 0; i < s.size(); i++){
            if ((i % 2 && s[i] != '1') ||  (i % 2 == 0 && s[i] != '0'))
                d1++;
            if ((i % 2 == 0 && s[i] != '1') ||  (i % 2 && s[i] != '0'))
                d2++;
        }
        return min(d1, d2);
    }
};

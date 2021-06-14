// OJ: https://leetcode.com/problems/count-binary-substrings/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/count-binary-substrings/discuss/108625/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int pre = 0, cur = 1;
        for (int i = 1; i < s.size(); i++){
            if (s[i] == s[i-1])
                cur++;
            else{
                ans += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return ans + min(cur, pre);
    }
};

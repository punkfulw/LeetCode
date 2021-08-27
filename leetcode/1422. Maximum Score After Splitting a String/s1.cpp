// OJ: https://leetcode.com/problems/maximum-score-after-splitting-a-string
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        for (auto c: s) 
            if (c == '1')
                ones++;
        int ans = s[0] == '1' ? ones - 1 : ones + 1, cur = ans;
        for (int i = 1; i < s.size()-1; i++){
            if (s[i] == '0')
                cur++;
            else
                cur--;
            ans = max(ans, cur);
        }
        return ans;
    }
};

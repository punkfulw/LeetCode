// OJ: https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/2224.%20Minimum%20Number%20of%20Operations%20to%20Convert%20Time/README.md
// Time: O(1)
// Space: O(1)
class Solution {
class Solution {
public:
    int gettime(string s)
    {
        int ret = 0;
        ret = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
        return ret;
    }
    
    int convertTime(string cur, string cor) {
        int ans = 0, dif = gettime(cor) - gettime(cur);
        int ops[4] = {60, 15, 5, 1};
        for (int i = 0; i < 4; i++)
        {
            ans += dif / ops[i];
            dif %= ops[i];
        }
        return ans;
    }
};

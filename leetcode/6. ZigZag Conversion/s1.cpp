// OJ: https://leetcode.com/problems/zigzag-conversion/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string convert(string s, int numRows) {
        if (s.size() <= numRows || numRows == 1)
            return s;
        vector<string> rec(numRows);
        int n = numRows + numRows - 2;
        for (int i = 0; i < s.size(); i++){
            int cur = i % n;
            int side = cur / (n / 2);
            if (side < 1)
                rec[cur] += s[i];
            else
                rec[numRows - 1 - cur % (n/2)] += s[i];
        }
        string ans
        for (auto str: rec)
            ans += str;
        return ans;
    }
};

// OJ: https://leetcode.com/problems/push-dominoes/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/push-dominoes/discuss/132332/JavaC%2B%2BPython-Two-Pointers
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string pushDominoes(string d) {
        d = "L" + d + "R";
        string ans;
        for (int i = 0, j = 1; j < d.size(); j++){
            if (d[j] == '.') continue;
            if (i > 0)
                ans += d[i];
            int mid = j - i - 1;
            if (d[i] == d[j])
                ans += string(mid, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                ans += string(mid, '.');
            else
                ans += string(mid/2, d[i]) + string(mid%2, '.') + string(mid/2, d[j]);
            i = j;
        }
        return ans;
    }
};

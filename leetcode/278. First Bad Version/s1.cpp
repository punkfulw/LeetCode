// OJ: https://leetcode.com/problems/first-bad-version/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;
        while (l <= r){
            int m = (r - l) / 2 + l;
            if (isBadVersion(m))
                r = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};

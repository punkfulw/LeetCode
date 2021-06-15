// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/binary-gap/discuss/149835/C%2B%2BJavaPython-Dividing-by-2
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        for (int d = -32; N; N /= 2, d++)
            if (N % 2) res = max(res, d), d = 0;
        return res;
    }
};

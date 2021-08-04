// OJ: https://leetcode.com/problems/pascals-triangle-ii/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/pascals-triangle-ii/discuss/38438/7-lines-C%2B%2B-solution-one-pass-O(k)-space-for-return-with-detailed-explanation
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex + 1, 1);
        long C = 1;
        for (int i = 1; i < rowIndex; i++) {
            C = C * (rowIndex - i + 1) / i;
            ret[i] = C;
        }
        return ret;
    }
};

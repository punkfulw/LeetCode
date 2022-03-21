// OJ: https://leetcode.com/problems/reducing-dishes/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/reducing-dishes/discuss/563384/JavaC%2B%2BPython-Easy-and-Concise
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] + total > 0; --i) {
            total += A[i];
            res += total;
        }
        return res;
    }
};

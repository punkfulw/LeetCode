// OJ: https://leetcode.com/problems/duplicate-zeros/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/duplicate-zeros/discuss/312727/C%2B%2BJava-Two-Pointers-Space-O(1)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void duplicateZeros(vector<int>& A) {
        int n = A.size(), j = n + count(A.begin(), A.end(), 0);
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n)
                A[j] = A[i];
            if (A[i] == 0 && --j < n)
                A[j] = 0;
        }
    }
};

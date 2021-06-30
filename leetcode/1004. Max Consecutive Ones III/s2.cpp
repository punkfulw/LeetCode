// OJ: https://leetcode.com/problems/max-consecutive-ones-iii/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/max-consecutive-ones-iii/discuss/247564/JavaC%2B%2BPython-Sliding-Window
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j;
        for (j = 0; j < A.size(); ++j) {
            if (A[j] == 0) K--;
            if (K < 0 && A[i++] == 0) K++;
        }
        return j - i;
    }
};

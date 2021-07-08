// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author: github.com/punkfulw
//Reference: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/378.%20Kth%20Smallest%20Element%20in%20a%20Sorted%20Matrix/README.md
// Time: O(Nlog(max(A)))
// Space: O(1)
class Solution {
    int rank(vector<vector<int>> &A, int num) {
        int N = A.size(), cnt = 0, j = N - 1;
        for (int i = 0; i < N; ++i) {
            while (j >= 0 && A[i][j] > num) --j;
            cnt += j + 1;
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& A, int k) {
        int N = A.size(), L = A[0][0], R = A[N - 1][N - 1];
        while (L < R) {
            int M = (L + R) / 2;
            if (rank(A, M) < k) L = M + 1;
            else R = M;
        }
        return L;
    }
};

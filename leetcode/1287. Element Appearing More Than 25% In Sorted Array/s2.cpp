// OJ: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), part = n / 4;
        for (int i = 0; i < N - part; ++i) {
            if (A[i] == A[i + part]) return A[i];
        }
        return -1;
    }
};

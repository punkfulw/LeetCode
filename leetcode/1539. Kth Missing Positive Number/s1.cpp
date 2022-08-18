// OJ: https://leetcode.com/problems/kth-missing-positive-number/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int idx = 0, n = arr.size(), i = 1;
        for (; i <= 1000 && idx < n; i++){
            if (i == arr[idx])
                idx++;
            else
                k--;
            if (k == 0)
                return i;
        }
        return i + k - 1;
    }
};

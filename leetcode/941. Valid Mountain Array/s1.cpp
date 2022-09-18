// OJ: https://leetcode.com/problems/valid-mountain-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int l = 0, n = arr.size(), r = n - 1;
        while (l < n - 1 && arr[l + 1] > arr[l])
            l++;
        while(r - 1 >= 0 && arr[r - 1] > arr[r])
            r--;
        return l != 0 && r != n - 1 && l == r;
    }
};

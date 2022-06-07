// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, idx = n + m - 1;
        while (i >= 0 || j >= 0){
            if (i >= 0 && j >= 0)
                nums1[idx--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
            else if (i >= 0)
                nums1[idx--] = nums1[i--];
            else
                nums1[idx--] = nums2[j--];
        }
        return;
    }
};

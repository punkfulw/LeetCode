// OJ: https://leetcode.com/problems/merge-sorted-array/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m-1, q = n-1, i = n+m-1;
        while (p >= 0 && q >= 0){
            if (nums1[p] > nums2[q])
                nums1[i--] = nums1[p--];
            else
                nums1[i--] = nums2[q--];
        }
        while (q >= 0)
            nums1[i--] = nums2[q--];
    }
};

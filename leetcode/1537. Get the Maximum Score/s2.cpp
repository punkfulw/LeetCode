// OJ: https://leetcode.com/problems/get-the-maximum-score/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(1)
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), MOD = 1e9 + 7;
        long long a = 0, b = 0, pre_a = 0, pre_b = 0;
        
        int i = 0, j = 0;
        while (i < n && j < m){
            if (nums1[i] < nums2[j])
                a = pre_a + nums1[i++];
            else if (nums1[i] == nums2[j]){
                b = a = max(pre_a, pre_b) + nums1[i];
                i++;
                j++;
            }
            else 
                b = pre_b + nums2[j++];
            pre_a = a;
            pre_b = b;
        }
        
        while (i < n)
            a += nums1[i++];

        while (j < m)
            b += nums2[j++];

        return max(a, b) % MOD;
    }
};


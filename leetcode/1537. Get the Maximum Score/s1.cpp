// OJ: https://leetcode.com/problems/get-the-maximum-score/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(max(N, M)
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), MOD = 1e9 + 7;
        vector<long long> dp1(n + 1), dp2(m + 1);
        
        int i = 0, j = 0;
        while (i < n && j < m){
            if (nums1[i] < nums2[j])
                dp1[i + 1] = dp1[i] + nums1[i++];
            else if (nums1[i] == nums2[j]){
                dp2[j + 1] = dp1[i + 1] = max(dp1[i], dp2[j]) + nums1[i];
                i++;
                j++;
            }
            else 
                dp2[j + 1] = dp2[j] + nums2[j++];
        }        
        while (i < n)
            dp1[i + 1] = dp1[i] + nums1[i++];
        while (j < m)
            dp2[j + 1] = dp2[j] + nums2[j++];

        return max(dp1[n], dp2[m]) % MOD;
    }
};

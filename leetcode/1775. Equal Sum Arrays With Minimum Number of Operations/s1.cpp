// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    void sol(vector<int> &nums1, vector<int> &nums2, int &ans){
        int cnt1 = accumulate(nums1.begin(), nums1.end(), 0), 
            cnt2 = accumulate(nums2.begin(), nums2.end(), 0);
        if (cnt1 == cnt2)
            return;
        if (cnt1 < cnt2){
            swap(nums1, nums2);
            swap(cnt1, cnt2);
        }
        sort(nums1.rbegin(), nums1.rend());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0, n = nums1.size(), m = nums2.size();
        while (cnt1 != cnt2){
            ans++;
            int d1 = i < n ? nums1[i] - 1 : 0, d2 = j < m ? 6 - nums2[j] : 0, dif = cnt1 - cnt2;
            if (max(d1, d2) >= dif)
                break;
            if (d1 > d2){
                cnt1 -= d1;
                i++;
            }
            else {
                cnt2 += d2;
                j++;
            }
            
        }
        return;
    }
    
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n > m * 6 || m > n * 6)
            return -1;
        int ans = 0;
        sol(nums1, nums2, ans);
        return ans;
    }
};

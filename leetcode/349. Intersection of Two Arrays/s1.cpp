// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++){
            if (count(nums2.begin(), nums2.end(), nums1[i]) && !count(ans.begin(), ans.end(), nums1[i]))
                ans.push_back(nums1[i]);
        }
        return ans;
    }
};

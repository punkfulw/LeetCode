// OJ: https://leetcode.com/problems/intersection-of-two-arrays/
// Author: github.com/punkfulw
// Time: O(N+M)
// Space: O(N)
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int num: nums2){
           if (s.erase(num))
               ans.push_back(num);
        }
        return ans;
    }
};

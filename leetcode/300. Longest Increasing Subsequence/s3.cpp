// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (auto i: nums){
            auto it = lower_bound(ans.begin(), ans.end(), i);
            if (it == ans.end())
                ans.push_back(i);
            else
                *it = i;
        }
        return ans.size();
    }
};

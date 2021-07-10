// OJ: https://leetcode.com/problems/longest-increasing-subsequence/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/longest-increasing-subsequence/discuss/74848/9-lines-C%2B%2B-code-with-O(NlogN)-complexity
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        
        for (int i = 0; i < nums.size(); i++){
            auto it = lower_bound(ans.begin(), ans.end(), nums[i]);
            if (it == ans.end())
                ans.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return ans.size();
    }
};

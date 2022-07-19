// OJ: https://leetcode.com/problems/find-target-indices-after-sorting-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        int small = 0, cnt = 0;
        for (auto i: nums){
            small += i < target;
            cnt += i == target;
        }
        while (cnt--)
            ans.push_back(small++);
        return ans;
    }
};

// OJ: https://leetcode.com/problems/two-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            if (mp.count(target - nums[i]))
                return { mp[target - nums[i]], i };
            mp[nums[i]] = i;
        }
        return {};
    }
};

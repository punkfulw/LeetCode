// OJ: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums.size(); i++){
            if (mp[nums[i]])
                return {mp[nums[i]], i+1};
            else
                mp[target - nums[i]] = i+1;
        }
        return {};
    }
};

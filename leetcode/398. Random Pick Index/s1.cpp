// OJ: https://leetcode.com/problems/random-pick-index/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int x = rand() % mp[target].size();
        return mp[target][x];
    }
};


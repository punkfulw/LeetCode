// OJ: https://leetcode.com/problems/contains-duplicate-ii/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++){
            int x = nums[i];
            if (mp.find(x) != mp.end())
                if (i - mp[x] <= k)
                    return true;
            mp[x] = i;
        }
        return false;
    }
};

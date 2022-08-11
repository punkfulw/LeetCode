// OJ: https://leetcode.com/problems/frog-jump/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool canCross(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, unordered_set<int>> mp;
        mp[1].insert(1);
        for (int i = 1; i < n; i++){
            int cur = nums[i];
            if (mp[cur].empty()) continue;
            for (auto k: mp[cur]){
                mp[cur + k - 1].insert(k - 1);
                mp[cur + k].insert(k);
                mp[cur + k + 1].insert(k + 1);
            }
        }
        return !mp[nums[n - 1]].empty();
    }
};

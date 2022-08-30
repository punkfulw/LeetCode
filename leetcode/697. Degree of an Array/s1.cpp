// OJ: https://leetcode.com/problems/degree-of-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, pair<int, int>> section;
        
        int mx = 0, ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            int x = nums[i];
            cnt[x]++;
            mx = max(mx, cnt[x]);
            if (section.find(x) != section.end())
                section[x].second = i;
            else
                section[x] = {i, i};
        }
        for (auto p: cnt)
            if (p.second == mx)
                ans = min(ans, section[p.first].second - section[p.first].first + 1);    
        return ans;
    }
};

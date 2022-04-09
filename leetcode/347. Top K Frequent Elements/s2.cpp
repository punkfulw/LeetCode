// OJ: https://leetcode.com/problems/top-k-frequent-elements/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(U)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        vector<int> ans;
        vector<vector<int>> buckets(n + 1);
        for (auto i: nums)
            cnt[i]++;
        
        for (auto p: cnt)
            buckets[p.second].push_back(p.first);
        
        for (int i = n; i >= 0 && ans.size() < k; i--)
        {
            if (!buckets[i].empty())
                ans.insert(ans.end(), buckets[i].begin(), buckets[i].end());
        }
        return ans;
    }
};

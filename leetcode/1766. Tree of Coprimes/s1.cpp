// OJ: https://leetcode.com/problems/tree-of-coprimes/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> mp[100001], nums, ans;
    
    void dfs(int root, vector<vector<pair<int, int>>>& aces, int pre, int L){
        int val = nums[root], idx = -1, lvl = -1;
        
        for (int i = 1; i <= 50; i++){
            if (gcd(i, val) != 1 || aces[i].size() == 0)
                continue;
            auto [level, index] = aces[i].back();
            if (level > lvl){
                lvl = level;
                idx = index;
            }
        }
        ans[root] = idx;
        aces[val].push_back({L, root});
        
        for (auto nxt: mp[root])
            if (nxt != pre)
                dfs(nxt, aces, root, L + 1);

        aces[val].pop_back();
    }
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        ans.resize(nums.size(), -1);
        this->nums = nums;
        
        for (auto e: edges){
            int a = e[0], b = e[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        
        vector<vector<pair<int, int>>> aces(51);
        dfs(0, aces, -1, 0);
        return ans;
    }
};

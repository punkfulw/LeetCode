// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Ref: https://youtu.be/nYFd7VHKyWQ
// Time: O(N!)
// Space: O(N)
class Solution {
    vector<int> digit;
    vector<int> cnt;
    vector<vector<int>> ans;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> mp;
        for (int num: nums)
            mp[num]++;
        for (auto p: mp){
            digit.push_back(p.first);
            cnt.push_back(p.second);
        }
        dfs(nums, 0, nums.size());
        return ans;
    }  
    
    void dfs(vector<int>& nums, int start, int n){
        if (start == n){
            ans.push_back(nums);
            return;
        }
        for (int i = 0; i < cnt.size(); i++){
            if (!cnt[i])
                continue;
            cnt[i]--;
            nums[start] = digit[i];
            dfs(nums, start+1, n);
            cnt[i]++;
        }
    }
};

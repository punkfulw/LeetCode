// OJ: https://leetcode.com/problems/sort-the-jumbled-numbers/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> rec(n);
        for (int i = 0; i < n; i++){
            string s = to_string(nums[i]);
            for (int j = 0; j < s.size(); j++){
                s[j] = mp[s[j] - '0'] + '0';
            }
            int cur = stoi(s);
            rec[i] = {cur, i};
        }
        sort(rec.begin(), rec.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = nums[rec[i].second];
        
        return ans;
    
    }
};

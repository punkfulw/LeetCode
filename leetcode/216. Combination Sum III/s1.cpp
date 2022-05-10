// OJ: https://leetcode.com/problems/combination-sum-iii/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> ans;
  
    void dfs(int k, int n, int sum, int j, vector<int> &nums)
    {
        if (k == nums.size())
        {
            if (sum == n)
                ans.push_back(nums);     
            return;
        }
        for (int i = j+1; i <= 9; i++)
        {
            nums.push_back(i);
            dfs(k, n, sum + i, i, nums);
            nums.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        dfs(k, n, 0, 0, nums);
            
        return ans;
    }
};

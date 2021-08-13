// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines
// Time: O(N!)
// Space: O(N)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        perm(0, n, nums, ans);
        return ans;
    }
    
    void perm(int i, int n, vector<int> nums, vector<vector<int>>& ans){
        if (i == n-1){
            ans.push_back(nums);
            return;
        }
        for (int j = i; j < n; j++){
            if (j != i && nums[i] == nums[j])
                continue;
            swap(nums[i], nums[j]);
            perm(i+1, n, nums, ans);
        }
        return;
    }  
};

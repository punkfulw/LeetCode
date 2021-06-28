// OJ: https://leetcode.com/problems/permutations/
// Author: github.com/punkfulw
// Time: O(N! * N)
// Space: O(N! * N)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        perm(ans, 0, nums);
        return ans;
    }
    void perm(vector<vector<int>>& ans, int begin, vector<int>& nums) {
        if (begin >= nums.size()){
            ans.push_back(nums);
            return;
        }
        for (int i = begin; i < nums.size(); i++){
            swap(nums[i], nums[begin]);
            perm(ans, begin+1, nums);
            swap(nums[i], nums[begin]);
        }
    }
};

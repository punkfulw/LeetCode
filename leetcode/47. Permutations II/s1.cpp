// OJ: https://leetcode.com/problems/permutations-ii
// Author: github.com/punkfulw
// Time: O(N!)
// Space: O(N^2)
class Solution {
    set<vector<int>> st;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        perm(0, n, nums, ans);
        return ans;
    }
    
    void perm(int i, int n, vector<int>& nums, vector<vector<int>>& ans){
        if (i == n)
            return;
        if (!st.count(nums)){
            st.insert(nums);
            ans.push_back(nums);
        }
        for (int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            perm(i+1, n, nums, ans);
            swap(nums[i], nums[j]);
        }
        return;
    }  
};

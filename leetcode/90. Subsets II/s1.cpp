// OJ: https://leetcode.com/problems/subsets-ii/
// Author: github.com/punkfulw
// Time: O(N^2 * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = pow(2, nums.size());
        vector<vector<int>> ans;
        
        for (int i = 0; i < n; i++){
            int index = 1, j = 0;
            vector<int> cur;
            while (index <= i){
                if (index & i)
                    cur.push_back(nums[j]);
                j++;
                index <<= 1;
            }
            if (find(ans.begin(), ans.end(), cur) == ans.end())
                ans.push_back(cur);
        }
        return ans;
    }
};

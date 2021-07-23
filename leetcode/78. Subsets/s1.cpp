// OJ: https://leetcode.com/problems/subsets
// Author: github.com/punkfulw
// Time: O(N * 2^N)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = 1 << nums.size();
        vector<vector<int>> ans(n);
        for (int index = 0; index < n; index++){
            int i = index, pos = 0;
            while (i > 0){
                if (i & 1)
                    ans[index].push_back(nums[pos]);
                pos++;
                i = i >> 1;
            }
        }
        return ans;
    }
};

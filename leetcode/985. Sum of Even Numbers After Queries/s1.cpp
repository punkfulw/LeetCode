// OJ: https://leetcode.com/problems/sum-of-even-numbers-after-queries/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int cur_sum = 0;
        vector<int> ans;
        for (int i: nums)
            if ((i & 1) == 0)
                cur_sum += i;
        int index, val;
        for (auto query: queries){
            index = query[1];
            val = query[0];
            if ((nums[index] & 1) == 0)
                cur_sum -= nums[index];
            nums[index] += val;
            if ((nums[index] & 1) == 0)
                cur_sum += nums[index];
            ans.push_back(cur_sum);
        }
        return ans;
    }
};

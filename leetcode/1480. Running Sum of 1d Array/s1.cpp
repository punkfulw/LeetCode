// OJ: https://leetcode.com/problems/running-sum-of-1d-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> sums {};
        int v_size = nums.size();
        sums.push_back(nums.at(0));
        for (int i = 1; i < v_size; i++){
            sums.push_back(sums.at(i-1) + nums.at(i));
        }
        return sums;
    }
};

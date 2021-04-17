// OJ: https://leetcode.com/problems/shuffle-the-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans = nums;
        for (int i = 0; i < n; i++){
            ans.at(i*2) = nums.at(i);
            ans.at(i*2+1) = nums.at(i+n);
        }
        return ans;
    }
};

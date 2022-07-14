// OJ: https://leetcode.com/problems/keep-multiplying-found-values-by-two/
// Author: github.com/lzl124631x
// Time: O(N)
// Space: O(U) unique num in nums
class Solution {
public:
    int findFinalValue(vector<int>& nums, int ori) {
        unordered_set<int> s(nums.begin(), nums.end());
        while (s.count(ori))
            ori *= 2;
        return ori;
    }
};

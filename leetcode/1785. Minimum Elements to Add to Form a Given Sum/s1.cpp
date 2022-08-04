// OJ: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = accumulate(nums.begin(), nums.end(), 0l), dif = abs(goal - sum);
        return dif % limit ? dif / limit + 1 : dif / limit;
    }
};

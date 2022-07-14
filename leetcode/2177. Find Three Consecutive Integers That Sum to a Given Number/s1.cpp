// OJ: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3) return {};
        return {num / 3 - 1, num / 3, num / 3 + 1};
    }
};

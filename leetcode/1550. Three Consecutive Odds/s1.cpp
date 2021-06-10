// OJ: https://leetcode.com/problems/three-consecutive-odds/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odd = 0;
        for (int i = 0; i < arr.size() && odd < 3; i++)
            odd = arr[i] % 2 == 0 ? 0 : odd + 1;
        return odd == 3;
    }
};

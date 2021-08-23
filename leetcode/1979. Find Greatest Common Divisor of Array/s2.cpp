// OJ: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        int ans;
        for (int i = 1; i <= mn; i++){
            if (mn % i == 0 && mx % i == 0)
                ans = i;
        }
        return ans;
    }
};

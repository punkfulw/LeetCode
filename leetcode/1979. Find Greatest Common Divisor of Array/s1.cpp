// OJ: https://leetcode.com/problems/find-greatest-common-divisor-of-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(logN)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());
        return gcd(mx, mn);
    }
    int gcd(int a, int b){
        if (b == 0) return a;
        return (gcd(b, a % b));
    }
};

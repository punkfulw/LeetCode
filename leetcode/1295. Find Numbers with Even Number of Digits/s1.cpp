// OJ: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans {};
        for (auto i: nums){
            int sum {};
            while (i >= 1){
                sum++;
                i /= 10;
            }
            if (sum % 2 == 0){
                ans++;
            }
        }
        return ans;
    }
};

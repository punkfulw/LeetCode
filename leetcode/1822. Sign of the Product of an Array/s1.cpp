// OJ: https://leetcode.com/problems/sign-of-the-product-of-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ans {};
        for (auto i: nums){
            if (i < 0)
                ans++;
            else if (i == 0)
                return 0;
        }
        return (ans % 2) ? -1 : 1;
    }
};

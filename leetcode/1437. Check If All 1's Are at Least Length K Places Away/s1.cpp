// OJ: https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int pre = -1;
        if (!k) return true; //edge case
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 1){
                if (pre != -1 && i - pre - 1 < k)
                    return false;
                pre = i;
            }  
        }
        return true;
    }
};

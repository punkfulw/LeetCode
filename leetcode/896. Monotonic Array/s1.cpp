// OJ: https://leetcode.com/problems/monotonic-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size(), dir = 0;
        if (n == 1) return true;
        
        for (int i = 1; i < n; i++){
            if (nums[i] < nums[i - 1]){
                if (dir == 1)
                    return false;
                if (dir == 0)
                    dir = -1;
            }  
            else if (nums[i] > nums[i - 1]){
                if (dir == -1)
                    return false;
                if (dir == 0)
                    dir = 1;
            }
        }
        return true;
    }
};

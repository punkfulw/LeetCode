// OJ: https://leetcode.com/problems/increasing-triplet-subsequence/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int a = INT_MAX, b = INT_MAX;
        for (int &x: nums) {
            if (x <= a)
                a = x;           
            else if (x <= b)
                b = x;          
            else            
                return true;      
        }
    return false;
    }
};

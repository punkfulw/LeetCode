// OJ: https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int mid = high - low + 1;
        if (low % 2 && high % 2)
            return mid / 2 + 1;
        return mid / 2;
            
    }
};

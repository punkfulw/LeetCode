// OJ: https://leetcode.com/problems/hamming-distance/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
        int xr = x ^ y;
        
        while (xr){
            if (xr%2 == 1)
                ans++;
            xr >>= 1;
        }
        return ans;
    }
};

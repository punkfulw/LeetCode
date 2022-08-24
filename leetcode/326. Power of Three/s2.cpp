// OJ: https://leetcode.com/problems/power-of-three/solution/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/power-of-three/discuss/77872/Without-log-and-O(1).
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int const Max3PowerInt = 1162261467; // 3^19, 3^20 = 3486784401 > MaxInt32
    int const MaxInt32 = 2147483647; // 2^31 - 1
    bool isPowerOfThree(int n) {
        if (n <= 0 || n > Max3PowerInt) return false;
        return Max3PowerInt % n == 0;
    }
};

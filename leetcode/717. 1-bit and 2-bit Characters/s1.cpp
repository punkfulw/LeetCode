// OJ: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        for (; i < n; i++){
            if (bits[i] == 1){
                if (i == n - 2)
                    return false;
                i++;
            }
        }
        return true;
    }
};

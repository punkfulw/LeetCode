// OJ: https://leetcode.com/problems/1-bit-and-2-bit-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size(), i = n - 2, cnt = 0;
        while (i >= 0 and bits[i] == 1){
            cnt++;
            i--;
        }
        
        return cnt % 2 == 0;
    }
};

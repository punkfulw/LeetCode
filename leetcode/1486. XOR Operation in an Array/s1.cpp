// OJ: https://leetcode.com/problems/xor-operation-in-an-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans {};
        for (int i = start; i < (start + n * 2); i += 2){
            ans = ans ^ i; 
            cout << ans << endl;
        }
        return ans;
    }
};

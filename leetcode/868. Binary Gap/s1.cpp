// OJ: https://leetcode.com/problems/binary-gap/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int binaryGap(int n) {
        int index = 1;
        int ans = 0, cur = 0, pre = -1;
        while (index <= n){
            if (index & n){
                if (pre == -1){
                    pre = cur;
                    continue;
                }
                ans = max(ans, cur-pre);
                pre = cur;
            }
            index <<= 1;
            cur++;
        }
        return ans;
    }
};

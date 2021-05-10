// OJ: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minPartitions(string n) {
        int ans {};
        
        for (auto c: n){
            ans = max(ans, c-'0');
            if (ans == 9)
                break;
        }
        return ans;
    }
};

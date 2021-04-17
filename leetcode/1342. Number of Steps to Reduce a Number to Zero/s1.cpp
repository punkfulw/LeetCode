// OJ: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
// Author: github.com/punkfulw
// Time: O(logN)
// Space: O(1)
class Solution {
public:
    int numberOfSteps(int num) {
        int ans {};
        while (num != 0){
            if (num % 2 == 0)
                num /= 2;
            else
                num -= 1;
            ans++;
        }
        return ans;
    }
};

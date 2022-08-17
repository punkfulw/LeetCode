// OJ: https://leetcode.com/problems/perfect-number/
// Author: github.com/punkfulw
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int cnt = 1;
        for (int i = 2; i * i <= num; i++)
            if (num % i == 0)
                cnt += i + num / i;
        return cnt == num && num != 1;
    }
};

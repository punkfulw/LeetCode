// OJ: https://leetcode.com/problems/three-divisors/
// Author: github.com/punkfulw
// Time: O(sqrt(N))
// Space: O(1)
class Solution {
public:
    bool isThree(int n) {
        int cnt = 0;
        for (int i = 1; i * i <= n; i++)
            if (n % i == 0){
                cnt++;
                if (n / i != i)
                    cnt++;
            }
        return cnt == 3;
    }
};

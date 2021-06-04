// OJ: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        set<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (int i = left; i <= right; i++){
            int cur = 0, num = i;
            while (num > 0){
                cur = cur + num % 2;
                num /= 2;
            }
            if (p.count(cur))
                ans++;
        }
        return ans;
    }
};

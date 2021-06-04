// OJ: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for (int i = left; i <= right; i++){
            int cur = 0, num = i;
            while (num > 0){
                cur = cur + num % 2;
                num /= 2;
            }
            if (isPrime(cur))
                ans++;
        }
        return ans;
    }
    
    bool isPrime(int n){
        if (n == 2) return true;
        if (n == 1 || n % 2 == 0) return false;
        for (int i = 3; i <= sqrt(n); i += 2){
            if (n % i == 0)
                return false;
        }
        return true;
    }
};

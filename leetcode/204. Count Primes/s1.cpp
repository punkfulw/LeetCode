// OJ: https://leetcode.com/problems/count-primes/
// Author: github.com/punkfulw
// Time: O(NloglogN)
// Space: O(N)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrimes(n, true);
        for (int i = 2; i * i < n; i++){
            if (!isPrimes[i])
                continue;
            for (int j = i * i; j < n; j += i){
                isPrimes[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++){
            if (isPrimes[i])
                cnt++;
        }
        return cnt;
    }
};

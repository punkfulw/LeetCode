// OJ: https://leetcode.com/problems/count-largest-group/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countLargestGroup(int n) {
        int sum[37] = {};
        int largest = 0;
        for (int i = 1; i <= n; i++)
            largest = max(largest, ++sum[dsum(i)]);
        return count(sum, sum+37, largest);
    }
    int dsum(int n){
        int sum = 0;
        while (n > 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
};

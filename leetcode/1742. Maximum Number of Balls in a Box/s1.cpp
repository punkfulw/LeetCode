// OJ: https://leetcode.com/problems/maximum-number-of-balls-in-a-box/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int digitSum(int n){
        int res =0;
        while (n > 0){
            res += n % 10;
            n /= 10;
        }
        return res;
    }
    int countBalls(int lowLimit, int highLimit) {
        vector<int> cnt(46, 0);
        
        for (int i = lowLimit; i <= highLimit; i++){
            cnt[digitSum(i)]++;
        }
        return *max_element(cnt.begin(), cnt.end());
    }
};

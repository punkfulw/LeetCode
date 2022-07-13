// OJ: https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/
// Author: github.com/punkfulw
// Time: O(1) 
// Space: O(1)
class Solution {
public:
    int minimumSum(int num) {
        vector<int> cnt;
        while (num){
            cnt.push_back(num % 10);
            num /= 10;
        }
        sort(cnt.begin(), cnt.end());
        return 10 * (cnt[0] + cnt[1]) + cnt[2] + cnt[3];
    }
};

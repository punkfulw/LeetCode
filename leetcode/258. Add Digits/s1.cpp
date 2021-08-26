
// OJ: https://leetcode.com/problems/add-digits/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int addDigits(int num) {
        while (num > 9){
            int cnt = 0;
            while (num > 0){
                cnt += num % 10;
                num /= 10;
            }
            num = cnt;
        }
        return num;
    }
};

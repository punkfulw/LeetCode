// OJ: https://leetcode.com/problems/integer-to-roman/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/integer-to-roman/discuss/6382/My-simple-cpp-solution
// Time: O(1)
// Space: O(1)
class Solution {
public:
    string intToRoman(int num) {
        int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string sym[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        
        int i = 0;
        while (num != 0){
            while (num >= val[i]){
                num -= val[i];
                ans += sym[i];
            }
            i++;
        }
        return ans;
    }
};

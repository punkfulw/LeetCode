// OJ: https://leetcode.com/problems/count-operations-to-obtain-zero/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int countOperations(int num1, int num2) {
        if (num1 == 0 || num2 == 0)
            return 0;
        if (num1 < num2)
            return num2 / num1 + countOperations(num1, num2 % num1); 
        else
            return num1 / num2 + countOperations(num1 % num2, num2); 
    }
};

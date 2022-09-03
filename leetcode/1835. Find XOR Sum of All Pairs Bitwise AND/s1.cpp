// OJ: https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
// Author: github.com/punkfulw
// Time: O(A + B)
// Space: O(1)
class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int num = 0, num2 = 0;
        for (int &i: arr1)
            num ^= i;
        
        for (int &i: arr2)
            num2 ^= i;

        return num & num2;
    }
};

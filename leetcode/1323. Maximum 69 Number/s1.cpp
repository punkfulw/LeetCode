// OJ: https://leetcode.com/problems/maximum-69-number
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int maximum69Number (int num) {
        int ans = num;
        int size = 1;
        int index {};
        
        while (ans > 0){
            if (ans % 10 == 6)
                index = size;
            ans /= 10;
            size++;
        }
        if (index == 0)
            return num;
        return num + 3 * pow(10, index-1);
    }
};

// OJ: https://leetcode.com/problems/reverse-only-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseOnlyLetters(string s) {
        for (int i = 0, j = s.size()-1; i < j;){
            while (!isalpha(s[i]) && i < j)
                i++;
            while (!isalpha(s[j]) && i < j)
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

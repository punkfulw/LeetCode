// OJ: https://leetcode.com/problems/reverse-vowels-of-a-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool vowel(char c){
        c = toupper(c);
        return c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U';
    }
    string reverseVowels(string s) {
        int i = 0, n = s.size(), j = n - 1;
        while (i < j){
            while (i < n && vowel(s[i]))
                i++;
            while (j >= 0 && vowel(s[j]))
                j--;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};

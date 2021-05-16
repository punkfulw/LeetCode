// OJ: https://leetcode.com/problems/reverse-words-in-a-string-iii/
// Author: github.com/punkfulw
// Refernce: https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/101906/C%2B%2B-Java-Clean-Code
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++){
            if (s[i] != ' '){
                int j = i;
                for (; j < n && s[j] != ' '; j++){}
                reverse(s.begin() + i, s.begin() + j);
                i = j - 1;
            }
        }
        return s;
    }
};

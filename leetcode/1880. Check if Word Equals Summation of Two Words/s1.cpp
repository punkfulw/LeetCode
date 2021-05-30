// OJ: https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int a = 0, b = 0, c = 0;
        int n = firstWord.size()-1;
        int m = secondWord.size()-1;
        int k = targetWord.size()-1;
        
        for (int i = n; i >= 0; i--)
            a = a + ((firstWord[i]-'a') * pow(10, n - i));
        for (int i = m; i >= 0; i--)
            b = b + ((secondWord[i]-'a') * pow(10, m - i));
        for (int i = k; i >= 0; i--)
            c = c + ((targetWord[i]-'a') * pow(10, k - i));
        return a+b == c;
    }
};

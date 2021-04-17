// OJ: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
// Author: github.com/punkfulw
// Time: O(M + N)
// Space: O(M + N)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string fir;
        string sec;
        for (auto c: word1){
            fir += c;
        }
        for (auto c: word2){
            sec += c;
        }
        return sec == fir;
    }
};

// OJ: https://leetcode.com/problems/maximum-repeating-substring/
// Author: github.com/punkfulw
// Time: O(N^3)
// Space: O(N)
class Solution {
public:
    int maxRepeating(string seq, string word) {
        int cnt = 0;
        string s = word;
        while (seq.find(s) != string::npos){
            cnt++;
            s += word;
        }
        return cnt;
    }
};

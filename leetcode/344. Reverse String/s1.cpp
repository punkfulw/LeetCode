// OJ: https://leetcode.com/problems/reverse-string/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++){
            swap(s[i], s[n-i-1]);
        }
    }
};

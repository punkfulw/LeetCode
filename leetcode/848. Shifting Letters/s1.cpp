// OJ: https://leetcode.com/problems/shifting-letters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string shiftingLetters(string s, vector<int>& nums) {
        int shift = 0;
        for (int i = s.size()-1; i >= 0; i--){
            shift = (nums[i] + shift) % 26;
            s[i] = (s[i] - 'a' + shift) % 26 + 'a';
        }
        return s;
    }
};

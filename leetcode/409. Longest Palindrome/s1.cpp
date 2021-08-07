// OJ: https://leetcode.com/problems/longest-palindrome/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) because there are at most 52 unique characters
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (auto c: s)
            mp[c]++;
        bool ones = false;
        int ans = 0;
        for (auto p: mp){
            if (p.second % 2 == 0)
                ans += p.second;
            else{
                ones = true;
                ans += (p.second / 2) * 2;
            }
        }
        ans += ones;
        return ans;
    }
};

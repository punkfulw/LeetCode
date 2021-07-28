// OJ: https://leetcode.com/problems/construct-k-palindrome-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canConstruct(string s, int k) {
        int map[26] = {};
        int cnt = 0, n = s.size();
        if (n < k) return false;
        if (k == n) return true;
        for (auto c: s)
            map[c-'a']++;
        for (auto i: map)
            if (i % 2)
                cnt++;
        return cnt <= k;
    }
};

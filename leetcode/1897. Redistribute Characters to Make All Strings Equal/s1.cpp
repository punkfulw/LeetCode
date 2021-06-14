// OJ: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int cnt[26] = {};
        int n = words.size();
        for (auto word: words)
            for (auto c: word)
                cnt[c - 'a']++;
        
        for (auto i: cnt)
            if (i % n != 0)
                return false;
        return true;
    }
};

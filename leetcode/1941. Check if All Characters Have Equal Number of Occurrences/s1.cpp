// OJ: https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(C) where C is the range of the characters
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt[26] = {};
        int num = 0;
        for (auto c: s){
            cnt[c-'a']++;
            num = cnt[c-'a'];
        }
        for(auto p:cnt)
            if (p && p != num)
                return false;
        return true;
    }
};

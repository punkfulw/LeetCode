// OJ: https://leetcode.com/problems/determine-if-two-strings-are-close/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool closeStrings(string s1, string s2) {
        if (s1.size() != s2.size())
            return false;
        array<int, 26> set1 = {}, set2 = {}, freq1 = {}, freq2 = {};
        
        for (auto &c: s1){
            freq1[c - 'a']++;
            set1[c - 'a'] = 1;
        }
        for (auto &c: s2){
            freq2[c - 'a']++;
            set2[c - 'a'] = 1;
        }
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return set1 == set2 and freq1 == freq2;
    }
};

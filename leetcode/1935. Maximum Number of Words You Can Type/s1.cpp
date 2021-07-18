// OJ: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        stringstream ss (text);
        string s;
        int ans = 0, num = 0;
        int cnt[26] = {0};
        for (char c: brokenLetters)
            cnt[c - 'a'] = 1;
        while (ss >> s){
            for (auto c: s){
                if (cnt[c-'a']){
                    ans++;
                    break;
                }
            }
            num++;
        }
        return num-ans;
    }
};

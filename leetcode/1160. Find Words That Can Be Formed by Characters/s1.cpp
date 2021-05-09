// OJ: https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(1)
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> cnt(26, 0) ;
        
        for (auto c: chars){
            cnt[c - 'a']++;
        }
        int ans {};
        for (auto s: words){
            vector<int> cnt1  {cnt};
            bool res = true;
            for (auto c: s){
                cnt1[c - 'a']--;
                if (cnt1[c - 'a'] < 0){
                    res = false;
                    break;
                }
            }
            if (res)
                ans += s.size();
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/check-if-the-sentence-is-pangram/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1) 
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt[26] {};
        
        for (auto c: sentence){
            cnt[c-'a']++;
        }
        for (auto i: cnt){
            if (i == 0)
                return false;
        }
        return true;
    }
};

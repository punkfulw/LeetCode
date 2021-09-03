// OJ: https://leetcode.com/problems/make-the-string-great/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(1)
class Solution {
public:
    string makeGood(string s) {
        bool move = true;
        while (move && s.size()){
            move = false;
            for (int i = 0; i < s.size()-1; i++){
                if (s[i] == s[i+1])
                    continue;
                if (toupper(s[i]) == s[i+1] || tolower(s[i]) == s[i+1]){
                    s.erase(i, 2);
                    i -= 2;
                    move = true;
                }
            }
        }
        return s;
    }
};

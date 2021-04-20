// OJ: https://leetcode.com/problems/determine-if-string-halves-are-alike/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt {};
        string vowel = "AEIOUaeiou";
        
        for (int i = 0; i < s.size()/2; i++){
            for (char c: vowel){
                if (s.at(i) == c)
                    cnt++;
            }
        }
        for (int i = s.size()/2; i < s.size(); i++){
            for (char c: vowel){
                if (s.at(i) == c)
                    cnt--;
            }
        }
        return cnt == 0 ? true : false ;
    }
};

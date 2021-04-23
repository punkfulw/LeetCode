// OJ: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string freqAlphabets(string s) {
        int size = s.size();
        string ans {};
        
        for (int i = size-1; i >= 0; i--){
            if (s[i] != '#')
                ans.push_back(s[i]+'a'- 48 - 1);
            else{
                int add = (s[i-2]-48) * 10 + (s[i-1] - 48) ;
                ans.push_back(add + 'a' - 1);
                i -= 2;
            } 
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

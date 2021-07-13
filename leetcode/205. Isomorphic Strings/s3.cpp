// OJ: https://leetcode.com/problems/isomorphic-strings/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/isomorphic-strings/discuss/57796/My-6-lines-solution
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp1[128] = {0}, mp2[128] = {0};
        for (int i = 0; i < s.size(); i++){
            if (mp1[s[i]] != mp2[t[i]])
                return false;
            mp1[s[i]] = i + 1;
            mp2[t[i]] = i + 1;
        }
        return true;
    }
};

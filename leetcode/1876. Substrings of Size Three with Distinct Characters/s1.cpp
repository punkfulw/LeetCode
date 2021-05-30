// OJ: https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countGoodSubstrings(string s) {
        int ret = 0;
        if (s.size() < 3)
            return 0;
        for (int i = 0; i < s.size()-2; i++){
            char a = s[i], b = s[i+1], c = s[i+2];
            if (a != b && a != c && b != c)
                ret++;
        }
        return ret;
    }
};

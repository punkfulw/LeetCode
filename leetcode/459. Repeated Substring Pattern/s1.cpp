// OJ: https://leetcode.com/problems/repeated-substring-pattern/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        string t;
        for (int i = 1; i <= n / 2; i++){
            t += s[i - 1];
            if (n % i)
                continue;
            int mul = n / i;
            string tmp = "";
            for (int j = 0; j < mul; j++)
                tmp += t;
            if (s == tmp)
                return true;
        }
        return false;
    }
};

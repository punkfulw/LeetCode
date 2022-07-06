// OJ: https://leetcode.com/problems/greatest-common-divisor-of-strings/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if (n < m) swap(str1, str2);
        for (int i = min(n, m); i >= 1; i--){
            if (n % i != 0 || m % i != 0)
                continue;
            string gcd = str1.substr(0, i), s1 = "", s2 = "";
            while (s1.size() < str1.size())
                s1 += gcd;
            while (s2.size() < str2.size())
                s2 += gcd;
            if (s1 == str1 && s2 == str2)
                return gcd;
        }
        return "";
    }
};

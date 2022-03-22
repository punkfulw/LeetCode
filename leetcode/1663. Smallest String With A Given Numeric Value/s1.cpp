// OJ: https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        for (int i = 0; i < n; i++)
        {  
            if (k <= (n - i - 1) * 26)
            {
                ans += 'a';
                k--;
            }
            else
            {
                int dif = k - (n - i - 1) * 26;
                ans += (dif + 'a' - 1);
                k -= dif;
            }
        }
        return ans;
    }
};

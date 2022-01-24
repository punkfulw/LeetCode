// OJ: https://leetcode.com/problems/detect-capital/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int n = word.size();
        int type = isupper(word[n - 1]) ? 0 : 1;
        for (int i = n - 2; i >= 1; i--)
        {
            int curT = isupper(word[i]) ? 0 : 1;
            if (type != curT)
                return false;
        }
        if (type == 0)
            return isupper(word[0]);
        return true;
    }
};

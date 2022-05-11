// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int dfs(int n, int prev, int pos)
    {
        if (pos == n)
            return 1;
        int cnt = 0;
        for (int i = 0; i < 5; i++)
            if (i >= prev)
                cnt += dfs(n, i, pos + 1);
        return cnt;
    }
    int countVowelStrings(int n) {
        return dfs(n, -1, 0);
    }
};

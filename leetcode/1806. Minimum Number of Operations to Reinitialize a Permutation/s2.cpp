// OJ: https://leetcode.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/minimum-number-of-operations-to-reinitialize-a-permutation/discuss/1130534/JavaC%2B%2BPython-6-lines-O(1)-Space
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int reinitializePermutation(int n) {
        int i = 1, cnt = 0;
        while (cnt == 0 || i > 1){
            if (i < n / 2)
                i *= 2;
            else
                i = 2 * i - n + 1;
            cnt++;
        }
        return cnt;
    }
};

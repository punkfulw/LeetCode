// OJ: https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        k %= accumulate(chalk.begin(), chalk.end(), 0l);
        for (auto i = 0; i < chalk.size(); i++){
            k -= chalk[i];
            if (k < 0)
                return i;
        }
        return 0;
    }
};

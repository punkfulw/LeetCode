// OJ: https://leetcode.com/problems/count-sorted-vowel-strings/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> cnt(5, 1);
        for (int i = 2; i <= n; i++){
            int sum = accumulate(cnt.begin(), cnt.end(), 0);
            for (int j = 0; j < 5; j++){
                int temp = cnt[j];
                cnt[j] = sum;
                sum -= temp;
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

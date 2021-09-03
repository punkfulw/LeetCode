// OJ: https://leetcode.com/contest/weekly-contest-234/problems/minimum-number-of-operations-to-reinitialize-a-permutation/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> rec (n), arr, copy;
        iota(rec.begin(), rec.end(), 0);
        int cnt = 0;
        arr = copy = rec;
        while (cnt == 0 || arr != rec){
            for (int i = 0; i < n; i++){
                if (i % 2 == 0)
                    arr[i] = copy[i/2];
                else
                    arr[i] = copy[n/2 + (i - 1) / 2];

            }
            copy = arr;
            cnt++;
        }
        return cnt;
    }
};

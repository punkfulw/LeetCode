// OJ: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
// Author: github.com/punkfulw
// Time: O(k * N^2 * logN)
// Space: O(N)
class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.size();
        string ori = num;
        while (k--){
            int pre = -1;
            for (int i = n - 2; i >= 0; i--){
                if (pre == num[i])
                    continue;
                pre = num[i];
                int j = n - 1;
                for (; j > i; j--){
                    if (num[j] > num[i])
                        break;
                }
                if (j == i)
                    continue;
                swap(num[i], num[j]);
                sort(num.begin() + i + 1, num.end());
                i = n - 2;
                break;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (num[i] == ori[i])
                continue;
            int j = i + 1;
            for (; j < n && num[j] != ori[i]; j++){}
            num = num.
        }
        return ans;
    }
};

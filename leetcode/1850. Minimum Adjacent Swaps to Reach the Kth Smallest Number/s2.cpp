// OJ: https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
public:
    int getMinSwaps(string num, int k) {
        int n = num.size();
        string ori = num;
        while (k--)
            next_permutation(num.begin(), num.end());

        int ans = 0;
        for (int i = 0; i < n; i++){
            if (num[i] == ori[i])
                continue;
            int j = i + 1;
            for (; j < n && num[j] != ori[i]; j++){}
            for (; j > i; j--){
                ans++;
                swap(num[j], num[j - 1]);
            }
        }
        return ans;
    }
};

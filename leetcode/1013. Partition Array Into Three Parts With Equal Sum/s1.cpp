// OJ: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0), num = sum / 3, n = arr.size();
        if (sum % 3)
            return false;
        int cnt1 = 0, cnt2 = 0, l = -1, r = -1;
        for (int i = 0, j = n - 1; i < n - 2; i++, j--){
            cnt1 += arr[i];
            cnt2 += arr[j];
            if (cnt1 == num && l == -1)
                l = i;
            if (cnt2 == num && r == -1)
                r = j;
        }
        return l != -1 && r != -1 && l < r - 1;
    }
};

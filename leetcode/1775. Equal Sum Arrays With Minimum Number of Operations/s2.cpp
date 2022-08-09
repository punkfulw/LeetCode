// OJ: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/discuss/1086142/C%2B%2BJava-O(n)
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minOperations(vector<int>& n1, vector<int>& n2) {
        int n = n1.size(), m = n2.size();
        if (n > m * 6 || m > n * 6)
            return -1;
        int cnt1 = accumulate(n1.begin(), n1.end(), 0), cnt2 = accumulate(n2.begin(), n2.end(), 0);
        if (cnt1 < cnt2)
            swap(n1, n2);
        int ans = 0, cnt[6] = {}, dif = abs(cnt1 - cnt2);
        
        for (int i: n1)
            cnt[i - 1]++;
        for (int i: n2)
            cnt[6 - i]++;
        
        for (int i = 5; i >= 1 && dif > 0; i--){
            int take = min(cnt[i], dif / i + (dif % i != 0));
            dif -= take * i;
            ans += take;
        }
        return ans;
    }
};

// OJ: https://leetcode.com/problems/finding-3-digit-even-numbers/
// Author: github.com/punkfulw
// Time: O(N + 10^3)
// Space: O(1)
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int cnt[10] = {};
        vector<int> ans;
        for (auto d: digits)
            cnt[d]++;
        
        for (int i = 100; i <= 998; i += 2){
            int cur[10] = {}, tmp = i, j = 0;
            while (tmp){
                cur[tmp % 10]++;
                tmp /= 10;
            }
            
            for (; j < 10; j++)
                if (cur[j] > cnt[j])
                    break;
            if (j == 10)
                ans.push_back(i);
        }
        return ans;
    }
};

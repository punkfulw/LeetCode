// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans, cnt(2e5 + 1);
        for (auto &i: changed)
            cnt[i]++;
        if (cnt[0] % 2 || n % 2)
            return ans;
        
        for (int i = 0; i <= 1e5; i++){
            int dou = i * 2, num = i == 0 ? cnt[i] / 2 : cnt[i];
            if (!num)
                continue;
            if (cnt[dou] < num)
                return {};
            cnt[dou] -= num;
            for (int j = 0; j < num; j++)
                ans.push_back(i);
        }
        return ans;
        
    }
};

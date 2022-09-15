// OJ: https://leetcode.com/problems/find-original-array-from-doubled-array/
// Author: github.com/punkfulw
// Time: O(NlogN) 
// Space: O(N)
class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> ans;
        map<int, int> cnt;
        for (auto &i: changed)
            cnt[i]++;
        if (cnt[0] % 2 || n % 2)
            return ans;
        
        for (auto &p: cnt){
            int cur = p.first, dou = cur * 2, num = cur == 0 ? p.second / 2 : p.second;
            if (!num)
                continue;
            if (cnt.find(dou) == cnt.end() || cnt[dou] < num)
                return {};
            cnt[dou] -= num;
            for (int i = 0; i < num; i++)
                ans.push_back(cur);
        }
        return ans;
        
    }
};

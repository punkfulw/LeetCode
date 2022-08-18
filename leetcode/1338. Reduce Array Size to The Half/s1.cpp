// OJ: https://leetcode.com/problems/reduce-array-size-to-the-half/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size(), half = (n + 1) / 2;
        unordered_map<int, int> mp;
        vector<int> cnt (n + 1);
        for (auto i: arr)
            mp[i]++;
        for (auto p: mp) 
            cnt[p.second]++;
        int ans = 0;
        for (int i = n; i >= 1 && half > 0; i--){
            while (cnt[i] && half > 0){
                half -= i;
                cnt[i]--;
                ans++;
            }
        }
        return ans;
    }
};

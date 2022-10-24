// OJ: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// Author: github.com/punkfulw
// Time: O(2^N)
// Space: O(N)
class Solution {
public:
    int n, ans = 0;
    
    void dfs(int idx, long long vis, vector<string> &arr){
        ans = max(ans, __builtin_popcount(vis));
        if (idx == n)
            return;
        for (int i = idx; i < n; ++i){
            long long nxt = 0LL, tmp;
            for (auto &c: arr[i])
                nxt |= (1 << (c - 'a'));

            if ((nxt & vis) == 0){
                tmp = vis | nxt;
                dfs(i + 1, tmp, arr);
            }
        }
    }
    
    int maxLength(vector<string>& arr) {
        n = arr.size();
        for (int i = n - 1; i >= 0; i--){
            unordered_set<char> set(arr[i].begin(), arr[i].end());
            if (set.size() != arr[i].size())
                arr.erase(arr.begin() + i);
        }
        n = arr.size();
        
        for (int i = 0; i < n; i++){
            long long vis = 0LL;
            for (auto &c: arr[i])
                vis |= (1 << (c - 'a'));
            dfs(i + 1, vis, arr);
        }
        
        return ans;
    }
};

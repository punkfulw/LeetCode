// OJ: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
// Author: github.com/punkfulw
// Ref: https://www.youtube.com/watch?v=jOI8_U-aenY
// Time: O(2^M * (M + N))
// Space: O(N)
class Solution {
public:
    bool check(int k, vector<vector<int>>& req){
        int cnt[20] = {};
        for (int b = 0; b < 16; b++){
            if (k & 1 << b){
                cnt[req[b][0]]--;
                cnt[req[b][1]]++;
            }
        }
        for (auto i: cnt)
            if (i != 0)
                return false;
        return true;
    }
    
    int maximumRequests(int n, vector<vector<int>>& req) {
        int m = req.size(), ans = 0;
        
        for (int k = 0; k < (1 << m); k++){
            if (check(k, req))
                ans = max(ans, __builtin_popcount(k));
        }
        return ans;
    }
};

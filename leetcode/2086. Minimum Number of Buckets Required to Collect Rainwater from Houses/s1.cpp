// OJ: https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool check(string &s, int i, int n){
        int l = i == 0 ? 1 : s[i - 1] == 'H';
        int r = i == n - 1 ? 1 : s[i + 1] == 'H';
        return l && r;
    }
    int minimumBuckets(string s) {
        int ans = 0, n = s.size();
        
        for (int i = 0; i < n; i++){
            if (s[i] != 'H' || i > 0 && s[i - 1] == 'D')
                continue;
            
            if (check(s, i, n))
                return -1;
            
            if (i < n - 1 && s[i + 1] == '.')
                s[i + 1] = 'D';
            ans++;
        }
        return ans;
    }
};

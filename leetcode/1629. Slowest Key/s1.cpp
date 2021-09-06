// OJ: https://leetcode.com/problems/slowest-key/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    char slowestKey(vector<int>& r, string keys) {
        char ans = keys[0];
        int dur = r[0];
        
        for (int i = 1; i < r.size(); i++){
            if (r[i] - r[i-1] >= dur){
                if (r[i] - r[i-1] == dur)
                    ans = max(ans, keys[i]);
                else
                    ans = keys[i];
                dur = r[i] - r[i-1];
            }
        }
        return ans;
    }
};

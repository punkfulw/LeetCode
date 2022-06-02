// OJ: https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values/
// Author: github.com/punkfulw
// Time: O(N^2)
// Space: O(N)
class Solution {
#define ull unsigned long long
public:
    bool dfs(int pos, ull prev, int n, string& s){
        if (prev > 1e10) return false;
        if (pos == n) return true;
        int found = 0;  
        for (int i = 1; i <= n - 1 && i + pos <= n; i++){
            string cur = s.substr(pos, i);
            ull num = stoull(cur);
            if (num == prev - 1)
                found |= dfs(pos + i, num, n, s);
        }
        return found;
    }
    
    bool splitString(string s) {
        int n = s.size(), ans = 0;
        for (int i = 1; i <= n - 1; i++){
            string cur = s.substr(0, i);
            ull prev = stoull(cur);
            ans |= dfs(i, prev, n, s);
        }
        return ans; 
    }
};

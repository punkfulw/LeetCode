// OJ: https://leetcode.com/problems/can-place-flowers
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    bool fit(vector<int>& f, int i){
        int l_ok = 0, r_ok = 0;
        if (i == 0)
            l_ok = 1;
        else 
            l_ok = f[i - 1] == 0;

        if (i == f.size() - 1)
            r_ok = 1;
        else 
            r_ok = f[i + 1] == 0;
        return r_ok && l_ok;
    }
    
    bool canPlaceFlowers(vector<int>& f, int n) {
        for (int i = 0; i < f.size(); ++i){
            if (f[i] == 0 && fit(f, i)){
                n--;
                f[i] = 1;
            }
        }
        return n <= 0;
    }
};

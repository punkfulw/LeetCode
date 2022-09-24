// OJ: https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int findBestValue(vector<int>& arr, int tar) {
        int n = arr.size(), ans = INT_MAX, dif = INT_MAX, l = 0, r = *max_element(arr.begin(), arr.end());
        
        while (l <= r){
            int m = (l + r) / 2, cnt = 0;
            for (auto &i: arr)
                cnt += i > m ? m : i;
            
            if (abs(cnt - tar) <= dif){
                if (abs(cnt - tar) == dif)
                    ans = min(ans, m);
                else
                    ans = m;
                dif = abs(cnt - tar);
            }
            if (cnt - tar >= 0)
                r = m - 1;
            else
                l = m + 1;
        }
        return ans;
    }
};

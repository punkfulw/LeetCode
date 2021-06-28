// OJ: https://leetcode.com/problems/candy/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int candy(vector<int>& r) {
        vector<int> cnt(r.size(), 1);
        if (r.size() == 1)
            return 1;
        for (int i = 1; i < r.size(); i++){
            if (r[i] > r[i-1])
                cnt[i] = cnt[i-1] + 1;
        }
        for (int i = r.size()-1; i > 0; i--){
            if (r[i] < r[i-1]){
                if (i-2 >= 0 && r[i-2] < r[i-1])
                    cnt[i-1] = max(cnt[i] + 1, cnt[i-2] + 1);
                else
                    cnt[i-1] = cnt[i] + 1;
            }
        }
        return accumulate(cnt.begin(), cnt.end(), 0);
    }
};

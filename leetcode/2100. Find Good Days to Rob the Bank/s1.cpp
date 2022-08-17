// OJ: https://leetcode.com/problems/find-good-days-to-rob-the-bank/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int k) {
        int n = sec.size(), pre = -1, cnt = 0;
        vector<int> valid(n), ans;
        
        for (int i = 0; i < n; i++){
            int cur = sec[i];
            if (pre < cur)
                cnt = 0;
            if (i >= k && cnt >= k)
                valid[i] = 1;
            cnt++;
            pre = cur;
        }
        pre = -1, cnt = 0;
        
        for (int i = n - 1; i >= 0; i--){
            int cur = sec[i];
            if (pre < cur)
                cnt = 0;
            if (valid[i] && n - i - 1 >= k && cnt >= k)
                ans.push_back(i);
            cnt++;
            pre = cur;
        }
        return ans;
    }
};


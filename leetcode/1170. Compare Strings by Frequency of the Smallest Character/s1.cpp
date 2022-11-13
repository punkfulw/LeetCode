// OJ: https://leetcode.com/problems/compare-strings-by-frequency-of-the-smallest-character/
// Author: github.com/punkfulw
// Time: O(NlogM)
// Space: O(M)
class Solution {
public:
    int cal_score(string &word){
        char sm = 'z';
        int cnt = 0;
        for (auto &c: word){
            if (c < sm){
                cnt = 1;
                sm = c;
            }
            else if (c == sm)
                cnt++;
        }
        return cnt;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& words) {
        int n = q.size(), m = words.size();
        vector<int> ans(n), scores(m);
        
        for (int i = 0; i < m; ++i)
            scores[i] = cal_score(words[i]);

        sort(scores.begin(), scores.end());
        
        for (int i = 0; i < n; i++){
            int cur = cal_score(q[i]);
            int greater_num = m - (upper_bound(scores.begin(), scores.end(), cur) - scores.begin());
            ans[i] = greater_num;
        }
        return ans;
    }
};

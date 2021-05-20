// OJ: https://leetcode.com/problems/find-common-characters/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(1)
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> cnt(26, INT_MAX);
        vector<string> ans {};
        
        for (auto s: A){
            vector<int> cnt1(26, 0);
            for (auto c: s)
                cnt1[c-'a']++;
            for (int i = 0; i < 26; i++)
                cnt[i] = min(cnt[i], cnt1[i]);
        }
        for (int i = 0; i < 26; i++){
            while (cnt[i] > 0){
                ans.push_back(string(1, i + 'a'));
                cnt[i]--;
            }
        }
        return ans;
    }
};

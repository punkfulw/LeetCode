// OJ: https://leetcode.com/problems/maximum-score-words-formed-by-letters/
// Author: github.com/punkfulw
// Time: O(2^N * CN) 
// Space: O(NC)
class Solution {
public:
    int ans = 0, n;
    void dfs(vector<string>& words, vector<int>& score, vector<int> cnt, int i, int sum){
        int enough = 1, point = 0;
        for (auto c: words[i]){
            int pos = c - 'a';
            cnt[pos]--;
            point += score[pos];
            if (cnt[pos] < 0){
                enough = 0;
                break;
            }
        }
        if (!enough) return;
        ans = max(ans, sum + point);
        for (int j = i + 1; j < n; j++)
            dfs(words, score, cnt, j, sum + point);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector<int> cnt(26, 0);
        for (auto c: letters)
            cnt[c - 'a']++;
        for (int i = 0; i < n; i++)
            dfs(words, score, cnt, i, 0);
        return ans;
        
    }
};

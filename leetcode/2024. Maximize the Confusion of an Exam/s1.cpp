// OJ: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    void sol(string &s, int k, char ch, int &ans){
        int n = s.size(), i = 0, j = 0;
        while (i < n && j < n){
            while (i < n && k < 0)
                k += s[i++] == ch;
            while (j < n && k >= 0)
                k -= s[j++] == ch;
            ans = max(ans, j - i - 1);
        }
        while (i < n && k < 0)
            k += s[i++] == ch;
        ans = max(ans, j - i);
        return;
    }
    
    int maxConsecutiveAnswers(string answerKey, int k) {
        int ans = 0;
        sol(answerKey, k, 'T', ans);
        sol(answerKey, k, 'F', ans);
        return ans;
    }
};

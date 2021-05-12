// OJ: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
// Author: github.com/punkfulw
// Time: O(K)
// Space: O(N)
class Solution {
public:
    int maxScore(vector<int>& C, int k) {
        vector<int> R = C;
        reverse(R.begin(), R.end());
        
        int cnt = 0, score = 0, win = k-1;
        
        for (int i = 0; i < k; i++){
            cnt += C[i]; 
        }
        score = cnt;
        for (int i = 0; i < k; i++){
            cnt = cnt - C[win--] + R[i];
            score = max(score, cnt);
        }
        return score;
    }
};

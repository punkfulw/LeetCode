// OJ: https://leetcode.com/problems/height-checker/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int cnt[101] {};
        
        for (auto i: heights){
            cnt[i]++;
        }
        
        int index = 0, ans = 0;
        for (int i = 1; i <= 100; i++){
            while (cnt[i] > 0){
                if (i != heights[index++])
                    ans++;
                cnt[i]--;
            }
        }
        return ans;
    }
};

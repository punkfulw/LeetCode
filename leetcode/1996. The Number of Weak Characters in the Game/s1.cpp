// OJ: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(), pro.end(), [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0]) 
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        int ans = 0, n = pro.size(), mx = 0;
        for (int i = n-1; i >= 0; i--){
            if (pro[i][1] < mx)
                ans++;
            mx = max(mx, pro[i][1]);
        }
        return ans;
    }
};

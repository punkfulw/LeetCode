// OJ: https://leetcode.com/problems/fruit-into-baskets/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int ans = 0, cnt = 0, n = fruits.size();
        
        for (int i = 0, j = 0; i < n; i++){
            int type = fruits[i];
            mp[type]++;
            cnt += 1;
            while (mp.size() > 2){
                int pre_fruit = fruits[j++];
                mp[pre_fruit]--;
                cnt--;
                if (mp[pre_fruit] == 0)
                    mp.erase(pre_fruit);
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};

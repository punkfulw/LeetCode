// OJ: https://leetcode.com/problems/minimum-operations-to-convert-number/
// Author: github.com/punkfulw
// Time: O(1000 * N)
// Space: O(1000)
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int step = 1, vis[1001] = {};
        queue<int> q;
        q.push(start);
        vis[start] = 1;
        
        while (!q.empty()){
            int sz = q.size();
            while (sz--){
                auto x = q.front();
                q.pop();
                for (auto &i: nums){
                    int a = x + i, b = x - i, c = x ^ i;
                    for (auto num: {a, b, c}){
                        if (num == goal)
                            return step;
                        if (num >= 0 && num <= 1000 && !vis[num]){
                            vis[num] = 1;
                            q.push(num);
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};

// OJ: https://leetcode.com/problems/rabbits-in-forest/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans = 0;
        unordered_map<int, int> map;
        for (auto num: answers) map[num]++;
        for (auto &[num, cnt] : map){
            if (num == 0){
                ans += cnt;
                continue;
            }
            int group = cnt / (num+1);
            if (cnt % (num+1)) group++;
            ans += group * (num + 1);
        }
        return ans;
    }
};

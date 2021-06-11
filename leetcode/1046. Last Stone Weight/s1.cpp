// OJ: https://leetcode.com/problems/last-stone-weight/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1){
            auto p1 = max_element(stones.begin(), stones.end());
            int a = *p1;
            stones.erase(p1);
            auto p2 = max_element(stones.begin(), stones.end());
            int b = *p2;
            stones.erase(p2);
            if (a != b)
                stones.push_back(abs(a-b));
        }
        return stones.size() == 0 ? 0 : stones[0];
    }
};

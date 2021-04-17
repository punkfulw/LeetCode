// OJ: https://leetcode.com/problems/jewels-and-stones/
// Author: github.com/punkfulw
// Time: O(N*M)
// Space: O(1)
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans {};
        for (int i = 0; i < jewels.size(); i++){
            for (int j = 0; j < stones.size(); j++){
                if (jewels.at(i) == stones.at(j))
                    ans++;
            }
        }
        return ans;
    }
};

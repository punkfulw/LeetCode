// OJ: https://leetcode.com/problems/greatest-sum-divisible-by-three/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int ans = 0, mx = 1e5;
        int one[2] = {mx, mx}, two[2] = {mx, mx};
        for (auto &i: nums){
            ans += i;
            if (i % 3 == 1){
                one[1] = min(one[1], i);
                if (one[0] > one[1])
                    swap(one[0], one[1]);
            }
            if (i % 3 == 2){
                two[1] = min(two[1], i);
                if (two[0] > two[1])
                    swap(two[0], two[1]);
            }
        }
        if (ans % 3 == 0)
            return ans;
        else if (ans % 3 == 1)
            return max({ans - two[0] - two[1], ans - one[0], 0});
        return max({ans - two[0], ans - one[0] - one[1], 0});
    }
};

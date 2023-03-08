// OJ: https://leetcode.com/problems/koko-eating-bananas/
// Author: github.com/punkfulw
// Time: O(N*logM) where N is the size of piles, M is ths sum of every pile.
// Space: O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r = 1e14 + 1, ans;

        while (l <= r){
            long long mid = (l + r) / 2, cnt = 0;
            
            for (auto i: piles){
                cnt += i / mid + (i % mid != 0);
            }
            if (cnt <= h){
                ans = mid;
                r = mid - 1;
            }
            else 
                l = mid + 1;
        }

        return ans;
    }
};

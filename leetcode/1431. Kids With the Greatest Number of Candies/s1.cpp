// OJ: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
// Author: github.com/punfkulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int can_size = candies.size();
        int max {};
        vector<bool> res (can_size);
        for (int i = 0; i < can_size; i++){
            if (candies.at(i) > max){
                max = candies.at(i);
            }else{
                res.at(i) = true;
            }
        }
        for (int i = 0; i < can_size; i++){
            if((candies.at(i) + extraCandies) < max){
                res.at(i) = false;
            }else{
                res.at(i) = true;
            }
        }
        return res;
    }
};

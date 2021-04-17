// OJ: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res {};
        if (n % 2 == 0){
            for (int i = 1; i <= n/2; i++){
                res.push_back(i);
                res.push_back(-i);
            }
        }else{
            res.push_back(0);
            for (int i = 1; i <= n/2; i++){
                res.push_back(i);
                res.push_back(-i);
            }
        }
        return res;
    }
};

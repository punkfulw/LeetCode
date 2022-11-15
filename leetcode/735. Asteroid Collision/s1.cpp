// OJ: https://leetcode.com/problems/asteroid-collision/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        
        for (auto &a: asteroids){
            int del = 0;
            while (!stk.empty() and stk.back() > 0 and a < 0){
                if (stk.back() >= -a){
                    del = 1;
                    if (stk.back() == -a)
                        stk.pop_back();
                    break;
                }
                else 
                    stk.pop_back();
                    
            }
            if (!del)
                stk.push_back(a);
        }
        return stk;
    }
};

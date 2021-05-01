// OJ: https://leetcode.com/problems/powerful-integers/
// Author: github.com/punkfulw
// Time: O(log_x^bound * log_y^bound)
// Space: O(log_x^bound * log_y^bound)
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> s;
        for (int i = 1; i < bound; i *= x){
            for (int j = 1; j < bound; j *= y){
                if (i + j <= bound)
                    s.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }
        return vector<int>(s.begin(), s.end());
    }
};

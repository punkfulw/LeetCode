// OJ: https://leetcode.com/problems/baseball-game/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> sum {};

        for (auto s: ops){
            if (s == "C")
                sum.pop_back();    
            else if (s == "+"){
                auto it = sum.end()-1;
                sum.push_back(*it + *(it-1));
            }    
            else if (s == "D"){
                auto it = sum.end()-1;
                sum.push_back(*it * 2);
            }
            else
                sum.push_back(stoi(s));
        }
        return accumulate(sum.begin(), sum.end(), 0);
    }
};

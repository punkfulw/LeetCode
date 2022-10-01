// OJ: https://leetcode.com/problems/fraction-to-recurring-decimal
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "";
        set<long long> app;
        long long front = (long long)numerator / denominator, 
                  remain = abs((long long)numerator % denominator), recur = 0;
        if (front >= 0 && numerator < 0 && denominator > 0 || numerator > 0 && denominator < 0)
            ans += "-";
        if (!remain)
            return ans + to_string(front);
        
        string tail = "";
        denominator = abs(denominator);
        int start = 0;
        
        while (remain != 0){
            remain *= 10;
            if (remain / denominator == 0){
                tail += ('0' + remain / denominator);
                continue;
            }
            if (app.find(remain) != app.end()){
                recur = 1;
                start = tail.find('0' + remain / denominator);
                break;
            }
            app.insert(remain);
            tail += ('0' + remain / denominator);
            remain %= denominator;
        }
        if (recur)
            return ans + to_string(front) + "." + tail.substr(0, start) + "(" + tail.substr(start) + ")";
        return ans + to_string(front) + "." + tail;
    }
};





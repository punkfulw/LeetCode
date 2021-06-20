// OJ: https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/
// Author: github.com/punkfulw
// Reference: https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/discuss/1284240/C%2B%2B-straightforward-3-lines
// Time: O(1)
// Space: O(1)
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start = stoi(startTime.substr(0, 2)) * 60 + stoi(startTime.substr(3, 2));
        int finish = stoi(finishTime.substr(0, 2)) * 60 + stoi(finishTime.substr(3, 2));
        if (start > finish)
            finish += 60 * 24;
        return max(0, finish / 15 - (start+14) / 15);
    }
};



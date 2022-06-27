// OJ: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(), n.end()) - '0';
    }
};

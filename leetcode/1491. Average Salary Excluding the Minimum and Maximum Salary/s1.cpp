// OJ: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    double average(vector<int>& salary) {
        auto min = min_element(begin(salary), end(salary));
        auto max = max_element(begin(salary), end(salary));
        double sum = accumulate(begin(salary), end(salary), 0.);
        sum = sum - *max - *min;
        return static_cast<double>(sum) / (salary.size() - 2);
    }
};

// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == points.size()) return points;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};

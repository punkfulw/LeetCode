// OJ: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> cnt;
        
        for (auto vec: matrix)
            for (int i: vec)
                cnt.push_back(i);
        
        sort(cnt.begin(), cnt.end());
        return cnt[k-1];
    }
};

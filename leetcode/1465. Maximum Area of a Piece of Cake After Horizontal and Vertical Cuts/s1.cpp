// OJ: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int v_size = verticalCuts.size(), h_size = horizontalCuts.size();
        auto v = max(verticalCuts[0], w - verticalCuts[v_size-1]);
        auto hi = max(horizontalCuts[0], h - horizontalCuts[h_size-1]);
        
        for (int i = 1; i < v_size; i++)
            v = max(v, verticalCuts[i]-verticalCuts[i-1]);
        for (int i = 1; i < h_size; i++)
            hi = max(hi, horizontalCuts[i]-horizontalCuts[i-1]);
        cout << v << " " << hi;
        return (long)v * hi % 1000000007;
    }
};

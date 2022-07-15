// OJ: https://leetcode.com/problems/max-chunks-to-make-sorted/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size(), ans = 0;
        for (int i = 0; i < n; i++){
            int cur = arr[i], mx = cur;
            while (mx > i && ++i < n)
                mx = max(mx, arr[i]);
            ans++;
        }
        return ans;
    }
};

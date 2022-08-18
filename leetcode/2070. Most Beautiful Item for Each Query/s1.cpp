// OJ: https://leetcode.com/problems/most-beautiful-item-for-each-query/
// Author: github.com/punkfulw
// Time: O(NlogN + M) 
// Space: O(1) inplace change
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& query) {
        int n = query.size(), m = items.size(), left = 0, right = m - 1;
        sort(items.begin(), items.end(), [&](vector<int> &a, vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        for (int i = 1; i < m; i++)
            items[i][1] = max(items[i - 1][1], items[i][1]);  

        for (int i = 0; i < n; i++){
            int l = left, r = right, q = query[i], ans = -1;
            while (l <= r){
                int mid = (l + r) / 2;
                if (items[mid][0] <= q){
                    l = mid + 1;
                    ans = mid;
                }
                else
                    r = mid - 1;
            }
            query[i] = ans == -1 ? 0 : items[ans][1];
        }
        return query;
    }
};

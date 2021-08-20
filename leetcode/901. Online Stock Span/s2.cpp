// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/online-stock-span/discuss/168311/C%2B%2BJavaPython-O(1)
// Time: O(1) amortized
// Space: O(N)
class StockSpanner {
public:
    stack<pair<int, int>> stk;
    StockSpanner() {}
    int next(int price) {
        int cnt = 1;
        while (!stk.empty() && price >= stk.top().first){
            cnt += stk.top().second;
            stk.pop();
        }
        stk.push({price, cnt});
        return cnt;
    }
};

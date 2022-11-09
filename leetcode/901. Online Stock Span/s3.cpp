// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class StockSpanner {
public:
    StockSpanner() {}    
    stack<pair<int, int>> stk;  // i, price
    int i = 0;
    
    int next(int price) {
        i++;
        while (!stk.empty() && price >= stk.top().second)
            stk.pop();
        int ans = stk.empty() ? i : i - stk.top().first;
        stk.push({i, price});
        return ans;
    }
};

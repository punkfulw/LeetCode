// OJ: https://leetcode.com/problems/online-stock-span/
// Author: github.com/punkfulw
// Time: O(N) 
// Space: O(N)
class StockSpanner {
public:
    vector<int> arr;
    StockSpanner() {}
    int next(int price) {
        arr.push_back(price);
        int cnt = 1;
        for (int i = arr.size()-2; i >= 0; i--){
            if (arr[i] <= price)
                cnt++;
            else 
                break;
        }
        return cnt;
    }
};

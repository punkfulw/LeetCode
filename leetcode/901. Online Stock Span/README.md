# [901. Online Stock Span (Medium)](https://leetcode.com/problems/online-stock-span/)

<p>Design an algorithm that collects daily price quotes for some stock and returns <code>the span</code> of that stock's price for the current day.</p>

<p>The <code>span</code> of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) for which the stock price was less than or equal to today's price.</p>


<il>
	<li>For example, if the price of a stock over the next 7 days were <code>[100, 80, 60, 70, 60, 75, 85]</code>, then the stock spans would be <code>[1, 1, 1, 2, 1, 4, 6]</code>.</li>
</il>

<p>Implement the <code>StockSpanner</code> class:</p>

<il>
	<li><code>StockSpanner()</code> Initializes the object of the class.</li>
  <li><code>int next(int price)</code> Returns the <b>span</b> of the stock's price given that today's price is <code>price</code>.</li>
</il>

<p>&nbsp;</p>

<div>
<p><strong>Example 1:</strong></p>

<pre><strong>Input: </strong><span id="example-input-1-1">["StockSpanner","next","next","next","next","next","next","next"]</span>, <span id="example-input-1-2">[[],[100],[80],[60],[70],[60],[75],[85]]</span>
<strong>Output: </strong><span id="example-output-1">[null,1,1,1,2,1,4,6]</span>
<strong>Explanation: </strong>
First, S = StockSpanner() is initialized.  Then:
S.next(100) is called and returns 1,
S.next(80) is called and returns 1,
S.next(60) is called and returns 1,
S.next(70) is called and returns 2,
S.next(60) is called and returns 1,
S.next(75) is called and returns 4,
S.next(85) is called and returns 6.

Note that (for example) S.next(75) returned 4, because the last 4 prices
(including today's price of 75) were less than or equal to today's price.
</pre>

<p>&nbsp;</p>

<p><strong>Constraints:</strong></p>
  
<il>
	<li><code>1 &lt;= price &lt;= 10<sup>5</sup></code>.</li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>next</code>.</li>
</il>
</div>


**Related Topics**:  
[Stack](https://leetcode.com/tag/stack/)

## Solution 1.


```cpp
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
```

## Solution 2. Monotonic Stack


```cpp
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
```

# [2070. Most Beautiful Item for Each Query (Medium)](https://leetcode.com/problems/most-beautiful-item-for-each-query/)

<p>You are given a 2D integer array <code>items</code> where <code>items[i] = [price<sub>i</sub>, beauty<sub>i</sub>]</code> denotes the <strong>price</strong> and <strong>beauty</strong> of an item respectively.</p>

<p>You are also given a <strong>0-indexed</strong> integer array <code>queries</code>. For each <code>queries[j]</code>, you want to determine the <strong>maximum beauty</strong> of an item whose <strong>price</strong> is <strong>less than or equal</strong> to <code>queries[j]</code>. If no such item exists, then the answer to this query is <code>0</code>.</p>

<p>Return <em>an array </em><code>answer</code><em> of the same length as </em><code>queries</code><em> where </em><code>answer[j]</code><em> is the answer to the </em><code>j<sup>th</sup></code><em> query</em>.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> items = [[1,2],[3,2],[2,4],[5,6],[3,5]], queries = [1,2,3,4,5,6]
<strong>Output:</strong> [2,4,5,5,6,6]
<strong>Explanation:</strong>
- For queries[0]=1, [1,2] is the only item which has price &lt;= 1. Hence, the answer for this query is 2.
- For queries[1]=2, the items which can be considered are [1,2] and [2,4]. 
  The maximum beauty among them is 4.
- For queries[2]=3 and queries[3]=4, the items which can be considered are [1,2], [3,2], [2,4], and [3,5].
  The maximum beauty among them is 5.
- For queries[4]=5 and queries[5]=6, all items can be considered.
  Hence, the answer for them is the maximum beauty of all items, i.e., 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> items = [[1,2],[1,2],[1,3],[1,4]], queries = [1]
<strong>Output:</strong> [4]
<strong>Explanation:</strong> 
The price of every item is equal to 1, so we choose the item with the maximum beauty 4. 
Note that multiple items can have the same price and/or beauty.  
</pre>

<p><strong>Example 3:</strong></p>

<pre><strong>Input:</strong> items = [[10,1000]], queries = [5]
<strong>Output:</strong> [0]
<strong>Explanation:</strong>
No item has a price less than or equal to 5, so no item can be chosen.
Hence, the answer to the query is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= items.length, queries.length &lt;= 10<sup>5</sup></code></li>
	<li><code>items[i].length == 2</code></li>
	<li><code>1 &lt;= price<sub>i</sub>, beauty<sub>i</sub>, queries[j] &lt;= 10<sup>9</sup></code></li>
</ul>


**Similar Questions**:
* [Closest Room (Hard)](https://leetcode.com/problems/closest-room/)

## Solution 1. 

```cpp
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
```

## Discuss

https://leetcode.com/problems/most-beautiful-item-for-each-query/discuss/1576065/C%2B%2B-Offline-Query

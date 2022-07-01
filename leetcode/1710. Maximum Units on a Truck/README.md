# [1710. Maximum Units on a Truck (Easy)](https://leetcode.com/problems/maximum-units-on-a-truck/)

<p>You are assigned to put some amount of boxes onto <strong>one truck</strong>. You are given a 2D array <code>boxTypes</code>, where <code>boxTypes[i] = [numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub>]</code>:</p>

<ul>
	<li><code>numberOfBoxes<sub>i</sub></code> is the number of boxes of type <code>i</code>.</li>
	<li><code>numberOfUnitsPerBox<sub>i</sub></code><sub> </sub>is the number of units in each box of the type <code>i</code>.</li>
</ul>

<p>You are also given an integer <code>truckSize</code>, which is the <strong>maximum</strong> number of <strong>boxes</strong> that can be put on the truck. You can choose any boxes to put on the truck as long as the number&nbsp;of boxes does not exceed <code>truckSize</code>.</p>

<p>Return <em>the <strong>maximum</strong> total number of <strong>units</strong> that can be put on the truck.</em></p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
<strong>Output:</strong> 8
<strong>Explanation:</strong> There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of the first and second types, and one box of the third type.
The total number of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> boxTypes = [[5,10],[2,5],[4,7],[3,9]], truckSize = 10
<strong>Output:</strong> 91
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= boxTypes.length &lt;= 1000</code></li>
	<li><code>1 &lt;= numberOfBoxes<sub>i</sub>, numberOfUnitsPerBox<sub>i</sub> &lt;= 1000</code></li>
	<li><code>1 &lt;= truckSize &lt;= 10<sup>6</sup></code></li>
</ul>


**Related Topics**:  
[Greedy](https://leetcode.com/tag/greedy/)

## Solution 1. Sort

We greedily pick the boxes with more units.

```cpp
// OJ: https://leetcode.com/problems/maximum-units-on-a-truck/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& box, int ts) {
        sort(box.begin(), box.end(), [](vector<int> &a, vector<int> &b){
            return a[1] > b[1];
        });
        int ans = 0, i = 0, n = box.size();
        while (ts && i < n){
            int take = min(ts, box[i][0]);
            ts -= take;
            ans += take * box[i++][1];
        }
        return ans;
    }
};
```

## Solution 2. Bucket Sort


```cpp
// OJ: https://leetcode.com/problems/maximum-units-on-a-truck/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(1)
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxs, int ts) {
        int ans = 0, i = 1000, n = boxs.size();
        int buckets[1001] = {};
        for (auto box: boxs)
            buckets[box[1]] += box[0];
        while (ts && i >= 0){
            if (buckets[i]){
                int take = min(ts, buckets[i]);
                ts -= take;
                ans += take * i;
            }
            i--; 
        }
        return ans;
    }
};
```

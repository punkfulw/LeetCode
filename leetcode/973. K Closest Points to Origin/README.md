# [973. K Closest Points to Origin (Medium)](https://leetcode.com/problems/k-closest-points-to-origin/)

<p>Given an array of <code>points</code> where <code>points[i] = [x<sub>i</sub>, y<sub>i</sub>]</code> represents a point on the <strong>X-Y</strong> plane and an integer <code>k</code>, return the <code>k</code> closest points to the origin <code>(0, 0)</code>.</p>

<p>The distance between two points on the <strong>X-Y</strong> plane is the Euclidean distance (i.e., <code>√(x<sub>1</sub> - x<sub>2</sub>)<sup>2</sup> + (y<sub>1</sub> - y<sub>2</sub>)<sup>2</sup></code>).</p>

<p>You may return the answer in <strong>any order</strong>. The answer is <strong>guaranteed</strong> to be <strong>unique</strong> (except for the order that it is in).</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/03/closestplane1.jpg" style="width: 400px; height: 400px;">
<pre><strong>Input:</strong> points = [[1,3],[-2,2]], k = 1
<strong>Output:</strong> [[-2,2]]
<strong>Explanation:</strong>
The distance between (1, 3) and the origin is sqrt(10).
The distance between (-2, 2) and the origin is sqrt(8).
Since sqrt(8) &lt; sqrt(10), (-2, 2) is closer to the origin.
We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> points = [[3,3],[5,-1],[-2,4]], k = 2
<strong>Output:</strong> [[3,3],[-2,4]]
<strong>Explanation:</strong> The answer [[-2,4],[3,3]] would also be accepted.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= points.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt; x<sub>i</sub>, y<sub>i</sub> &lt; 10<sup>4</sup></code></li>
</ul>


**Companies**:  
[Facebook](https://leetcode.com/company/facebook), [Amazon](https://leetcode.com/company/amazon), [DoorDash](https://leetcode.com/company/doordash), [Google](https://leetcode.com/company/google), [Microsoft](https://leetcode.com/company/microsoft), [LinkedIn](https://leetcode.com/company/linkedin), [Uber](https://leetcode.com/company/uber), [Asana](https://leetcode.com/company/asana), [Flipkart](https://leetcode.com/company/flipkart)

**Related Topics**:  
[Array](https://leetcode.com/tag/array/), [Math](https://leetcode.com/tag/math/), [Divide and Conquer](https://leetcode.com/tag/divide-and-conquer/), [Geometry](https://leetcode.com/tag/geometry/), [Sorting](https://leetcode.com/tag/sorting/), [Heap (Priority Queue)](https://leetcode.com/tag/heap-priority-queue/), [Quickselect](https://leetcode.com/tag/quickselect/)

**Similar Questions**:
* [Kth Largest Element in an Array (Medium)](https://leetcode.com/problems/kth-largest-element-in-an-array/)
* [Top K Frequent Elements (Medium)](https://leetcode.com/problems/top-k-frequent-elements/)
* [Top K Frequent Words (Medium)](https://leetcode.com/problems/top-k-frequent-words/)
* [Find Nearest Point That Has the Same X or Y Coordinate (Easy)](https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/)

## Solution 1. Sort

```cpp
// OJ: https://leetcode.com/problems/k-closest-points-to-origin/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(1)
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (k == points.size()) return points;
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return vector<vector<int>> (points.begin(), points.begin() + k);
    }
};
```




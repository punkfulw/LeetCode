# [295. Find Median from Data Stream (Hard)](https://leetcode.com/problems/find-median-from-data-stream/)

<p>Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.</p>
For example,

<p><code>[2,3,4]</code>, the median is <code>3</code></p>

<p><code>[2,3]</code>, the median is <code>(2 + 3) / 2 = 2.5</code></p>

<p>Design a data structure that supports the following two operations:</p>

<ul>
	<li>void addNum(int num) - Add a integer number from the data stream to the data structure.</li>
	<li>double findMedian() - Return the median of all elements so far.</li>
</ul>

<p>&nbsp;</p>

<p><strong>Example:</strong></p>

<pre>addNum(1)
addNum(2)
findMedian() -&gt; 1.5
addNum(3) 
findMedian() -&gt; 2
</pre>

<p>&nbsp;</p>

<p><strong>Follow up:</strong></p>

<ol>
	<li>If all integer numbers from the stream are between 0&nbsp;and 100, how would you optimize it?</li>
	<li>If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?</li>
</ol>


**Related Topics**:  
[Heap](https://leetcode.com/tag/heap/), [Design](https://leetcode.com/tag/design/)

**Similar Questions**:
* [Sliding Window Median (Hard)](https://leetcode.com/problems/sliding-window-median/)

## Solution 1. Min-Heap & Max Heap

```cpp
// OJ: https://leetcode.com/problems/find-median-from-data-stream/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/find-median-from-data-stream/discuss/74062/Short-simple-JavaC%2B%2BPython-O(log-n)-%2B-O(1)
// Time: O(logN)
// Space: O(N)
class MedianFinder {
    priority_queue<long> small, large;
public:
    void addNum(int num) {
        small.push(num);
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()){
            small.push(-large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top() : (small.top() - large.top()) / 2.0;
    }
};

```


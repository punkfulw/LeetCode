# [1670. Design Front Middle Back Queue (Medium)](https://leetcode.com/problems/design-front-middle-back-queue/)

<p>Design a queue that supports <code>push</code> and <code>pop</code> operations in the front, middle, and back.</p>

<p>Implement the <code>FrontMiddleBack</code> class:</p>

<ul>
	<li><code>FrontMiddleBack()</code> Initializes the queue.</li>
	<li><code>void pushFront(int val)</code> Adds <code>val</code> to the <strong>front</strong> of the queue.</li>
	<li><code>void pushMiddle(int val)</code> Adds <code>val</code> to the <strong>middle</strong> of the queue.</li>
	<li><code>void pushBack(int val)</code> Adds <code>val</code> to the <strong>back</strong> of the queue.</li>
	<li><code>int popFront()</code> Removes the <strong>front</strong> element of the queue and returns it. If the queue is empty, return <code>-1</code>.</li>
	<li><code>int popMiddle()</code> Removes the <strong>middle</strong> element of the queue and returns it. If the queue is empty, return <code>-1</code>.</li>
	<li><code>int popBack()</code> Removes the <strong>back</strong> element of the queue and returns it. If the queue is empty, return <code>-1</code>.</li>
</ul>

<p><strong>Notice</strong> that when there are <b>two</b> middle position choices, the operation is performed on the <strong>frontmost</strong> middle position choice. For example:</p>

<ul>
	<li>Pushing <code>6</code> into the middle of <code>[1, 2, 3, 4, 5]</code> results in <code>[1, 2, <u>6</u>, 3, 4, 5]</code>.</li>
	<li>Popping the middle from <code>[1, 2, <u>3</u>, 4, 5, 6]</code> returns <code>3</code> and results in <code>[1, 2, 4, 5, 6]</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong>
["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
[[], [1], [2], [3], [4], [], [], [], [], []]
<strong>Output:</strong>
[null, null, null, null, null, 1, 3, 4, 2, -1]

<strong>Explanation:</strong>
FrontMiddleBackQueue q = new FrontMiddleBackQueue();
q.pushFront(1);   // [<u>1</u>]
q.pushBack(2);    // [1, <u>2</u>]
q.pushMiddle(3);  // [1, <u>3</u>, 2]
q.pushMiddle(4);  // [1, <u>4</u>, 3, 2]
q.popFront();     // return 1 -&gt; [4, 3, 2]
q.popMiddle();    // return 3 -&gt; [4, 2]
q.popMiddle();    // return 4 -&gt; [2]
q.popBack();      // return 2 -&gt; []
q.popFront();     // return -1 -&gt; [] (The queue is empty)
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= val &lt;= 10<sup>9</sup></code></li>
	<li>At most&nbsp;<code>1000</code>&nbsp;calls will be made to&nbsp;<code>pushFront</code>,&nbsp;<code>pushMiddle</code>,&nbsp;<code>pushBack</code>, <code>popFront</code>, <code>popMiddle</code>, and <code>popBack</code>.</li>
</ul>


**Related Topics**:  
[Linked List](https://leetcode.com/tag/linked-list/), [Design](https://leetcode.com/tag/design/), [Dequeue](https://leetcode.com/tag/dequeue/)

**Similar Questions**:
* [Design Circular Deque (Medium)](https://leetcode.com/problems/design-circular-deque/)
* [Design Circular Queue (Medium)](https://leetcode.com/problems/design-circular-queue/)

## Solution 1. 

```cpp
// OJ: https://leetcode.com/problems/design-front-middle-back-queue/
// Author: github.com/punkfulw
// Time: O(N^2) 
// Space: O(N)
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}
    
    vector<int> nums;

    void pushFront(int val) {
        nums.insert(nums.begin(), val);
    }
    
    void pushMiddle(int val) {
        int pos = nums.size() / 2;
        nums.insert(nums.begin() + pos, val);
    }
    
    void pushBack(int val) {
        nums.push_back(val);
    }
    
    int popFront() {
        if (nums.empty())
            return -1;
        int ret = nums[0];
        nums.erase(nums.begin());
        return ret;
    }
    
    int popMiddle() {
        if (nums.empty())
            return -1;
        int sz = nums.size();
        int pos = sz % 2 ? sz / 2 : sz / 2 - 1;
        int ret = nums[pos];
        nums.erase(nums.begin() + pos);
        return ret;
    }
    
    int popBack() {
        if (nums.empty())
            return -1;
        int ret = nums.back();
        nums.pop_back();
        return ret;
    }
};
```

## Solution 2. 

```cpp
// OJ: https://leetcode.com/problems/design-front-middle-back-queue/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/design-front-middle-back-queue/discuss/951993/C%2B%2B-two-deques-O(1)-for-all
// Time: O(N) 
// Space: O(N)
class FrontMiddleBackQueue {
public:
    FrontMiddleBackQueue() {}
    
    deque<int> a, b;

    void adjust(){
        if (a.size() > b.size()){
            b.push_front(a.back());
            a.pop_back();
        }
        if (b.size() > a.size() + 1){
            a.push_back(b.front());
            b.pop_front();
        }
    }
    void pushFront(int val) {
        a.push_front(val);
        adjust();
    }
    
    void pushMiddle(int val) {
        a.push_back(val);
        adjust();
    }
    
    void pushBack(int val) {
        b.push_back(val);
        adjust();
    }
    
    int popFront() {
        if (a.empty() and b.empty())
            return -1;
        int ret;
        if (!a.empty()){
            ret = a.front();
            a.pop_front();
        }
        else {
            ret = b.front();
            b.pop_front();
        }
        adjust();
        return ret;
    }
    
    int popMiddle() {
        if (a.empty() and b.empty())
            return -1;
        int ret;
        if (a.size() == b.size()){
            ret = a.back();
            a.pop_back();
        }
        else {
            ret = b.front();
            b.pop_front();
        }
        adjust();
        return ret;
    }
    
    int popBack() {
        if (a.empty() and b.empty())
            return -1;
        int ret;
        if (!b.empty()){
            ret = b.back();
            b.pop_back();
        }
        else {
            ret = a.back();
            a.pop_back();
        }
        
        adjust();
        return ret;
    }
};
```

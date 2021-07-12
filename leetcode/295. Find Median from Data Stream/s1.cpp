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


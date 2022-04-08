// OJ: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Author: github.com/punkfulw
// Time:
//     KthLargest: O(NlogK)
//     add: O(logK)
// Space: O(N)
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (auto i: nums)
        {
            pq.push(i);
            if (pq.size() > K)
                pq.pop();
         }    
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > K)
            pq.pop();
        return pq.top();
    }
};

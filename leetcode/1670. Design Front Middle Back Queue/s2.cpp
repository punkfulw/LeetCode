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

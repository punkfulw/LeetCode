// OJ: https://leetcode.com/problems/peeking-iterator/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/peeking-iterator/discuss/1055887/C%2B%2B-or-Iterators-or-Caching-or-0ms-Beats-100-or-Explanation
// Time: O(1)
// Space: O(1) 
class PeekingIterator : public Iterator {
    int nextval;
    bool hasnext;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    hasnext = Iterator::hasNext();
        if (hasnext)
            nextval = Iterator::next();
	}
	
	int peek() {
        return nextval;
	}
	
	int next() {
        int cur = nextval;
	    hasnext = Iterator::hasNext();
        if (hasnext)
            nextval = Iterator::next();
        return cur;
	}
	
	bool hasNext() const {
	    return hasnext;
	}
};

// OJ: https://leetcode.com/problems/iterator-for-combination/
// Author: github.com/punkfulw
// Ref: https://github.com/lzl124631x/LeetCode/edit/master/leetcode/1286.%20Iterator%20for%20Combination/README.md
// Time:
//      CombinationIterator: O(S)
//      next: O(L)
//      hasNext: O(1)
// Space: O(S)
class CombinationIterator {
    vector<int> index;
    string s;
public:
    CombinationIterator(string s, int len) : s(s), index(len) {
        iota(begin(index), end(index), 0);
    }
    string next() {
        string ans; 
        for (int n : index) ans += s[n];
        for (int i = index.size() - 1; i >= 0; --i) {
            if (i > 0 && index[i] == s.size() - index.size() + i) continue;
            ++index[i++];
            for (; i < index.size(); ++i) index[i] = index[i - 1] + 1;
            break;
        }
        return ans;
    }
    bool hasNext() {
        return index[0] <= s.size() - index.size();
    }
};

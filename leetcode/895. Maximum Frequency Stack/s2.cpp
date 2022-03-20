// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/maximum-frequency-stack/discuss/163410/C%2B%2BJavaPython-O(1)
// Time: O(1)
// Space: O(N)
class FreqStack {
public:
    int maxfreq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    
    FreqStack() {
    }
    
    void push(int val) {
        maxfreq = max(maxfreq, ++freq[val]);
        m[freq[val]].push(val);
    }
    
    
    int pop() {
        int ans = m[maxfreq].top();
        m[maxfreq].pop();
        freq[ans]--;
        if (!m[maxfreq].size())
            maxfreq--;
        return ans;
    }
};

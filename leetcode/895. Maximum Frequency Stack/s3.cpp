// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Time: O(NlogN)
// Space: O(N)
class FreqStack {
public:
    unordered_map<int, int> val2freq;
    map<int, vector<list<int>::iterator>> freq2iter;
    
    list<int> List;
    
    FreqStack() {
    }
    
    void push(int val) {
        List.push_back(val);
        val2freq[val]++;
        int freq = val2freq[val];
        freq2iter[freq].push_back(--List.end());
    }
    
    int pop() {
        int freq = (--freq2iter.end())->first;
        auto it = freq2iter[freq].back();
        int val = *it;
        val2freq[val]--;
        freq2iter[freq].pop_back();
        if (freq2iter[freq].empty())
            freq2iter.erase(freq);
        List.erase(it);
        
        return val;
    }
};

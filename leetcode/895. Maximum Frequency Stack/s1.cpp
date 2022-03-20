// OJ: https://leetcode.com/problems/maximum-frequency-stack/
// Author: github.com/punkfulw
// Time: O(NlogN) for keeping the pq sorted
// Space: O(N)
class FreqStack {
public:
    int pos = 0;
    unordered_map<int, int> mp;
    priority_queue<vector<int>> pq;
    
    FreqStack() {
    }
    
    void push(int val) {
        mp[val]++;
        pq.push({mp[val],pos++,val});
    }
    
    
    int pop(){
        auto mx = pq.top(); 
        pq.pop(); 
        --mp[mx[2]]; 
        return mx[2];
    }
};

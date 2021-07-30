// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/punkfulw
// Time: O(N)
// Space: O(N)
class MapSum {
public:
    unordered_map<string, int> map;
    MapSum() {}
    
    void insert(string key, int val) {
        map[key] = val;
    }
  
    int sum(string prefix) {
        int ans = 0;
        for (auto p: map){
            int n = p.first.size();
            int m = prefix.size();
            if (n < m)
                continue;
            if (p.first.substr(0, m) == prefix)
                ans += p.second;
        }
        return ans;
    }
};

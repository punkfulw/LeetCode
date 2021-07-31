// OJ: https://leetcode.com/problems/map-sum-pairs/
// Author: github.com/punkfulw
// Ref: https://leetcode.com/problems/map-sum-pairs/discuss/1371761/C%2B%2BPython-Trie-and-HashMap-Clean-and-Concise
// Ref: https://leetcode.com/problems/map-sum-pairs/discuss/107554/C%2B%2B-O(1)-9-lines-Trie-%2B-Hash-map
// Time: 
//       insert: O(K), where K <= 50 is length of key string.
//       sum: O(P), where P <= 50 is length of prefix string.
// Space: O(T), where T is the total of nodes after inserting all key string, T <= sum length of all key strings.
class MapSum {
    struct Trie{
        Trie* child[26] = {};
        int sum = 0;
    } root;
    unordered_map<string, int> map;
public:
    
    void insert(string key, int val) {
        int dif = val - map[key];
        auto p = &root;
        for (auto c: key){
            c -= 'a';
            if (p->child[c] == NULL)
                p->child[c] = new Trie;
            p = p->child[c] ;
            p->sum += dif;
        }
        map[key] = val;
    }
    
    int sum(string prefix) {
        auto p = &root;
        for (auto c: prefix){
            c -= 'a';
            if (p->child[c] == NULL)
                return 0;
            p = p->child[c];
        }
        return p->sum;
    }
};

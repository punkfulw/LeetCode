// OJ: https://leetcode.com/problems/design-hashmap/
// Author: github.com/punkfulw
// Time: O(1)
// Space: O(1)
class MyHashMap {
private:
    int prime;
    vector<vector<pair<int, int>>> table;
    
    int hash(int key){
        return key % prime;
    }
    
    int search(int key) {
        int h = hash(key);
        for (int i = 0; i < table[h].size(); i++)
            if (table[h][i].first == key)
                return i;
        return -1;
    }
    
public:
    MyHashMap() {
        prime = 100007;
        table = vector<vector<pair<int, int>>>(prime);
    }
    
    void put(int key, int value) {
        int h = hash(key), pos = search(key);
        if (pos == -1)
            table[h].push_back({key, value});
        else
            table[h][pos].second = value;
    }
    
    int get(int key) {
        int h = hash(key), pos = search(key);
        if (search(key) == -1)
            return -1;
        return table[h][pos].second;
    }
    
    void remove(int key) {
        int h = hash(key), pos = search(key);
        if (pos == -1)
            return;
        table[h].erase(table[h].begin() + pos);
    }
};

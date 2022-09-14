// OJ: https://leetcode.com/problems/detect-squares/
// Author: github.com/punkfulw
// Time:
//      DetectSquares: O(1)
//      add: O(1)
//      count: O(NM) 
// Space: O(NN)
class DetectSquares {
public:
    const int n = 1001;
    int G[1001][1001] = {};
    DetectSquares() {}
    
    void add(vector<int> point) {
        int x = point[0], y = point[1];
        G[x][y]++;
    }
    
    int cal(int &x, int &c, int &y, int &len, int dir){
        return G[x][c] * G[x + len * dir][c] * G[x + len * dir][y];
    }
    
    bool check(int x){
        return x >= 0 && x < n;
    }
    
    int count(vector<int> point) {
        int x = point[0], y = point[1], ans = 0;
        for (int c = 0; c < n; c++){
            if (c == y) continue;
            if (G[x][c]){
                int len = y - c;
                if (check(x + len))
                    ans += cal(x, c, y, len, 1);
                if (check(x - len))
                    ans += cal(x, c, y, len, -1);
            }
        }
        return ans;
    }
};

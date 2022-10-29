class BIT{
private:
    int n;
    vector<int> arr;
    int getNext(int idx){
        return idx + (idx & (-idx));
    }
    int getParent(int idx){
        return idx & (idx-1);
    }
public:
    BIT(int _n):n(_n), arr(_n+1){
        arr[0] = 0;
        for(int idx = 0; idx < n; ++idx){
            addValue(idx, 1);
        }

    }
    void addValue(int idx, int val){
        ++idx;
        while(idx < arr.size()){
            arr[idx] += val;
            idx = getNext(idx);                
        }
    }
    int getSum(int idx){
        ++idx;
        int sum = 0;
        while(idx > 0){
            sum += arr[idx];
            idx = getParent(idx);
        }
        return sum;
    }
};

class SegmentTree{
private:
    int N;
    vector<int> tree;
    
    void insert(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                insert(2 * node + 1, l, mid, POS, VAL);
            }else{
                insert(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int findLeftmostStartIndex(int node, int l, int r, const int& MAX_VAL){
        if(l == r){
            if(tree[node] > MAX_VAL){
                return r + 1;
            }else{
                return r;
            }
        }
        int mid = (l + r) / 2;
        if(tree[2 * node + 2] > MAX_VAL){
            return findLeftmostStartIndex(2 * node + 2, mid + 1, r, MAX_VAL);
        }
        return findLeftmostStartIndex(2 * node + 1, l, mid, MAX_VAL);
    }
    
public:
    SegmentTree(){
        
    }
    
    void init(int N){
        this->N = N;
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.assign(2 * minLeaves, 0);
    }
    
    void insert(const int& POS, const int& VAL){
        insert(0, 0, N - 1, POS, VAL);
    }
    
    int findLeftmostStartIndex(const int& MAX_VAL){
        return findLeftmostStartIndex(0, 0, N - 1, MAX_VAL);
    }
};

class StockSpanner {
private:
    const int MAX_CALLS = 1e4 + 5;
    SegmentTree tree;
    int index;
    
public:
    StockSpanner() {
        tree.init(MAX_CALLS);
        index = -1;
    }
    
    int next(int price) {
        index += 1;
        tree.insert(index, price);
        return index - tree.findLeftmostStartIndex(price) + 1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class SegmentTree{
private:
    const int N = (int)1e4 + 7;
    vector<int> tree;

    void insert(int node, int l, int r, const int& L, const int& R, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
            return;
        }
        int mid = (l + r) / 2;
        if(POS <= mid){
            insert(2 * node, l, mid, L, R, POS, VAL);
        }else{
            insert(2 * node + 1, mid + 1, r, L, R, POS, VAL);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    
    int get_max_seq_length(int node, int l, int r, const int& L, const int& R, const int& POS, const int& VAL){
        // Case 1
        if(l == r){
            return POS - r;
        }
        int mid = (l + r) / 2;
        int left_son = 2 * node;
        int right_son = 2 * node + 1;
        // Case 2
        if(tree[right_son] > VAL){
            return get_max_seq_length(right_son, mid + 1, r, L, R, POS, VAL);
        }
        // Case 3
        return get_max_seq_length(left_son, l, mid, L, R, POS, VAL);
    }
    
public:
    SegmentTree() {
        tree.resize(4 * N);
    }
    
    void insert(const int& POS, const int& VAL){
        insert(1, 1, N, 1, N, POS, VAL);
    }
    
    int get_max_seq_length(const int& POS, const int& VAL){
        return get_max_seq_length(1, 1, N, 1, N, POS, VAL);
    }
};

class StockSpanner {
private:
    SegmentTree seg_tree;
    int stock_size;
    
public:
    StockSpanner() {
        stock_size = 1;
        seg_tree.insert(stock_size, (int)1e9);
    }
    
    int next(int price) {
        ++stock_size;
        seg_tree.insert(stock_size, price);
        return seg_tree.get_max_seq_length(stock_size, price);
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
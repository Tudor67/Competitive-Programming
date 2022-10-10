class SegmentTree{
private:
    const int N;
    unordered_map<int, int> lazy;
    unordered_map<int, int> tree;
    
    void add(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(R < l || r < L){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            add(2 * node + 1, l, mid, L, R, VAL);
            add(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = max(lazy[2 * node + 1] + tree[2 * node + 1],
                             lazy[2 * node + 2] + tree[2 * node + 2]);
        }
    }
    
public:
    SegmentTree(const int& N): N(N){
        
    }
    
    void add(const int& L, const int& R, const int& VAL){
        add(0, 0, N - 1, L, R, VAL);
    }
    
    int getMax(){
        return lazy[0] + tree[0];
    }
};

class MyCalendarThree {
private:
    const int N = 1e9;
    SegmentTree tree;
    
public:
    MyCalendarThree(): tree(N) {
        
    }
    
    int book(int start, int end) {
        tree.add(start, end - 1, 1);
        return tree.getMax();
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
class SegmentTree{
private:
    using PLL = pair<long long, long long>;
    const long long MODULO;
    int N;
    vector<PLL> tree;

    PLL aggregate(const PLL& L, const PLL& R){
        long long A = L.first, B = L.second;
        long long C = R.first, D = R.second;
        return {C * A % MODULO, (C * B + D) % MODULO};
    }

    void update(int node, int l, int r, const int& POS, const PLL& COEF){
        if(l == r){
            tree[node] = COEF;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, COEF);
            }else{
                update(2 * node + 2, mid + 1, r, POS, COEF);
            }
            tree[node] = aggregate(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    PLL query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return {1, 0};
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return aggregate(query(2 * node + 1, l, mid, L, R),
                         query(2 * node + 2, mid + 1, r, L, R));
    }

    void rebuildTree(int node, int l, int r){
        if(l == r){
            // leaf node is ok
        }else{
            int mid = (l + r) / 2;
            rebuildTree(2 * node + 1, l, mid);
            rebuildTree(2 * node + 2, mid + 1, r);
            tree[node] = aggregate(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void init(){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves - 1, {1, 0});
        copy(tree.end() - minLeaves - minLeaves / 2, tree.end() - minLeaves, tree.end() - minLeaves);
        rebuildTree(0, 0, N - 1);
    }

    void doubleTreeSize(){
        N *= 2;
        init();
    }

public:
    SegmentTree(const long long MODULO): MODULO(MODULO){
        N = 2;
        init();
    }

    void update(const int& POS, const PLL& COEF){
        while(POS >= N){
            doubleTreeSize();
        }
        update(0, 0, N - 1, POS, COEF);
    }

    PLL query(const int& L, const int& R){
        if(L > R){
            return {1, 0};
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Fancy {
private:
    const long long MODULO = 1e9 + 7;
    vector<long long> values;
    vector<long long> operationIndices;
    long long currentOperationIndex;
    SegmentTree tree;

public:
    Fancy(): tree(MODULO){
        currentOperationIndex = 0;
    }
    
    void append(int val) {
        values.push_back(val);
        operationIndices.push_back(currentOperationIndex + 1);
    }
    
    void addAll(int inc) {
        currentOperationIndex += 1;
        tree.update(currentOperationIndex, {1, inc});
    }
    
    void multAll(int m) {
        currentOperationIndex += 1;
        tree.update(currentOperationIndex, {m, 0});
    }
    
    int getIndex(int idx) {
        if(idx >= (int)values.size()){
            return -1;
        }
        pair<long long, long long> coef = tree.query(operationIndices[idx], currentOperationIndex);
        return (values[idx] * coef.first + coef.second) % MODULO;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
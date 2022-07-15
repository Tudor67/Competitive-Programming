template <class T, T (*F)(T, T)>
class SegmentTree{
private:
    const int N;
    vector<T> tree;
    
    void buildTree(int node, int l, int r, const T& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, VAL);
            buildTree(2 * node + 2, mid + 1, r, VAL);
            tree[node] = F(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void update(int node, int l, int r, const int& POS, const T& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = F(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    T query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return F(query(2 * node + 1, l, mid, L, R), 
                 query(2 * node + 2, mid + 1, r, L, R));
    }
    
    int getFirstIdxWithValAtLeast(int node, int l, int r, const T& VAL_THR){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(tree[2 * node + 1] >= VAL_THR){
            return getFirstIdxWithValAtLeast(2 * node + 1, l, mid, VAL_THR);
        }
        return getFirstIdxWithValAtLeast(2 * node + 2, mid + 1, r, VAL_THR);
    }
    
public:
    SegmentTree(const int& N, const T& VAL): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        
        tree.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, VAL);
    }
    
    void update(const int& POS, const T& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    T query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
    
    int getFirstIdxWithValAtLeast(const T& VAL_THR){
        return getFirstIdxWithValAtLeast(0, 0, N - 1, VAL_THR);
    }
};

class Functions{
public:
    static int maxFunction(int a, int b){
        return max(a, b);
    }

    static long long sumFunction(long long a, long long b){
        return a + b;
    }
};

class BookMyShow {
private:
    const int ROWS;
    const int COLS;
    vector<int> firstFreeColAt;
    int rowWithSomeFreeSeats;
    SegmentTree<int, Functions::maxFunction> maxSegmentTree;
    SegmentTree<long long, Functions::sumFunction> sumSegmentTree;
    
public:
    BookMyShow(int n, int m): ROWS(n), COLS(m), maxSegmentTree(ROWS, COLS), sumSegmentTree(ROWS, COLS) {
        firstFreeColAt.resize(ROWS, 0);
        rowWithSomeFreeSeats = 0;
    }
    
    vector<int> gather(int k, int maxRow) {
        int maxFreeSeats = maxSegmentTree.query(0, maxRow);
        if(maxFreeSeats < k){
            return {};
        }
        
        int row = maxSegmentTree.getFirstIdxWithValAtLeast(k);
        firstFreeColAt[row] += k;
        maxSegmentTree.update(row, COLS - firstFreeColAt[row]);
        sumSegmentTree.update(row, COLS - firstFreeColAt[row]);
        
        return {row, firstFreeColAt[row] - k};
    }
    
    bool scatter(int k, int maxRow) {
        long long freeSeats = sumSegmentTree.query(0, maxRow);
        if(freeSeats < k){
            return false;
        }
        
        while(rowWithSomeFreeSeats < ROWS && k > 0){
            int takenSeats = min(k, COLS - firstFreeColAt[rowWithSomeFreeSeats]);
            
            k -= takenSeats;
            firstFreeColAt[rowWithSomeFreeSeats] += takenSeats;
            
            maxSegmentTree.update(rowWithSomeFreeSeats, COLS - firstFreeColAt[rowWithSomeFreeSeats]);
            sumSegmentTree.update(rowWithSomeFreeSeats, COLS - firstFreeColAt[rowWithSomeFreeSeats]);
            if(firstFreeColAt[rowWithSomeFreeSeats] == COLS){
                rowWithSomeFreeSeats += 1;
            }
        }
        
        return true;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */
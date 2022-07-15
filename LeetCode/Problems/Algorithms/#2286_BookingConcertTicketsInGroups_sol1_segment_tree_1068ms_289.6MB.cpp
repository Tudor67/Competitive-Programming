class SegmentTree{
private:
    const int N;
    vector<long long> maximum;
    vector<long long> sum;
    
    void buildTree(int node, int l, int r, const long long& VAL){
        if(l == r){
            maximum[node] = VAL;
            sum[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, VAL);
            buildTree(2 * node + 2, mid + 1, r, VAL);
            maximum[node] = max(maximum[2 * node + 1], maximum[2 * node + 2]);
            sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
        }
    }
    
    void update(int node, int l, int r, const int& POS, const long long& VAL){
        if(l == r){
            maximum[node] = VAL;
            sum[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            maximum[node] = max(maximum[2 * node + 1], maximum[2 * node + 2]);
            sum[node] = sum[2 * node + 1] + sum[2 * node + 2];
        }
    }
    
    long long getSum(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return sum[node];
        }
        int mid = (l + r) / 2;
        return getSum(2 * node + 1, l, mid, L, R) +
               getSum(2 * node + 2, mid + 1, r, L, R);
    }
    
    long long getMaximum(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return -1;
        }
        if(L <= l && r <= R){
            return maximum[node];
        }
        int mid = (l + r) / 2;
        return max(getMaximum(2 * node + 1, l, mid, L, R),
                   getMaximum(2 * node + 2, mid + 1, r, L, R));
    }
    
    int getFirstIdxWithValAtLeast(int node, int l, int r, const long long& VAL_THR){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(maximum[2 * node + 1] >= VAL_THR){
            return getFirstIdxWithValAtLeast(2 * node + 1, l, mid, VAL_THR);
        }
        return getFirstIdxWithValAtLeast(2 * node + 2, mid + 1, r, VAL_THR);
    }
    
public:
    SegmentTree(const int& N, const long long& VAL): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        
        maximum.resize(2 * minLeaves);
        sum.resize(2 * minLeaves);
        buildTree(0, 0, N - 1, VAL);
    }
    
    long long getMaximum(const int& L, const int& R){
        return getMaximum(0, 0, N - 1, L, R);
    }
    
    int getFirstIdxWithValAtLeast(const long long& VAL_THR){
        return getFirstIdxWithValAtLeast(0, 0, N - 1, VAL_THR);
    }
    
    long long getSum(const int& L, const int& R){
        return getSum(0, 0, N - 1, L, R);
    }
    
    void update(const int& POS, const long long& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
};

class BookMyShow {
private:
    const int ROWS;
    const int COLS;
    vector<int> firstFreeColAt;
    int rowWithSomeFreeSeats;
    SegmentTree segmentTree;
    
public:
    BookMyShow(int n, int m): ROWS(n), COLS(m), segmentTree(ROWS, COLS) {
        firstFreeColAt.resize(ROWS, 0);
        rowWithSomeFreeSeats = 0;
    }
    
    vector<int> gather(int k, int maxRow) {
        long long maxFreeSeats = segmentTree.getMaximum(0, maxRow);
        if(maxFreeSeats < k){
            return {};
        }
        
        int row = segmentTree.getFirstIdxWithValAtLeast(k);
        firstFreeColAt[row] += k;
        segmentTree.update(row, COLS - firstFreeColAt[row]);
        
        return {row, firstFreeColAt[row] - k};
    }
    
    bool scatter(int k, int maxRow) {
        long long freeSeats = segmentTree.getSum(0, maxRow);
        if(freeSeats < k){
            return false;
        }
        
        while(rowWithSomeFreeSeats < ROWS && k > 0){
            int takenSeats = min(k, COLS - firstFreeColAt[rowWithSomeFreeSeats]);
            
            k -= takenSeats;
            firstFreeColAt[rowWithSomeFreeSeats] += takenSeats;
            
            segmentTree.update(rowWithSomeFreeSeats, COLS - firstFreeColAt[rowWithSomeFreeSeats]);
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
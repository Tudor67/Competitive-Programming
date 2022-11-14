class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void add(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] += VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                add(2 * node + 1, l, mid, POS, VAL);
            }else{
                add(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int kthElement(int node, int l, int r, int k){
        if(l == r){
            return r;
        }
        int mid = (l + r) / 2;
        if(tree[2 * node + 1] >= k){
            return kthElement(2 * node + 1, l, mid, k);
        }
        return kthElement(2 * node + 2, mid + 1, r, k - tree[2 * node + 1]);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void add(const int& POS, const int& VAL){
        add(0, 0, N - 1, POS, VAL);
    }
    
    int kthElement(int k){
        return kthElement(0, 0, N - 1, k);
    }
    
    int getTotalSum(){
        return tree[0];
    }
};

class MedianFinder {
private:
    static const int MIN_ELEM = -1e5;
    static const int MAX_ELEM =  1e5;
    static const int SHIFT = -MIN_ELEM;
    SegmentTree tree;
    
public:
    MedianFinder(): tree(MAX_ELEM + SHIFT + 1){
        
    }
    
    void addNum(int num) {
        tree.add(num + SHIFT, 1);
    }
    
    double findMedian() {
        int numsSize = tree.getTotalSum();
        return (tree.kthElement((numsSize - 1) / 2 + 1) - SHIFT +
                tree.kthElement(numsSize / 2 + 1) - SHIFT) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
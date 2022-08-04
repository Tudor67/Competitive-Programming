class SegmentTree{
public:
    int l;
    int r;
    int maxVal;
    int lazyVal;
    SegmentTree* leftChild;
    SegmentTree* rightChild;
    
    void propagate(SegmentTree* node){
        node->maxVal += node->lazyVal;
        if(node->l < node->r){
            int mid = (node->l + node->r) / 2;
            if(node->leftChild == nullptr){
                node->leftChild = new SegmentTree(node->l, mid);
            }
            if(node->rightChild == nullptr){
                node->rightChild = new SegmentTree(mid + 1, node->r);
            }
            node->leftChild->lazyVal += node->lazyVal;
            node->rightChild->lazyVal += node->lazyVal;
        }
        node->lazyVal = 0;
    }
    
    void add(SegmentTree* node, const int& L, const int& R, const int& VAL){
        propagate(node);
        if(node->r < L || R < node->l){
            // stop
        }else if(L <= node->l && node->r <= R){
            node->lazyVal += VAL;
            propagate(node);
        }else{
            int mid = (node->l + node->r) / 2;
            add(node->leftChild, L, R, VAL);
            add(node->rightChild, L, R, VAL);
            node->maxVal = max(node->leftChild->maxVal, node->rightChild->maxVal);
        }
    }
    
    int query(SegmentTree* node, const int& L, const int& R){
        propagate(node);
        if(node->r < L || R < node->l){
            return 0;
        }
        if(L <= node->l && node->r <= R){
            return node->maxVal;
        }
        int mid = (node->l + node->r) / 2;
        return max(query(node->leftChild, L, R),
                   query(node->rightChild, L, R));
    }
    
public:
    SegmentTree(int l, int r, int maxVal = 0, int lazyVal = 0, SegmentTree* leftChild = nullptr, SegmentTree* rightChild = nullptr):
                l(l), r(r), maxVal(maxVal), lazyVal(lazyVal), leftChild(leftChild), rightChild(rightChild){
                    
    }
    
    ~SegmentTree(){
        delete leftChild;
        delete rightChild;
    }
    
    void add(const int& L, const int& R, const int& VAL){
        add(this, L, R, VAL);
    }
    
    int query(const int& L, const int& R){
        return query(this, L, R);
    }
};

class MyCalendarTwo {
private:
    SegmentTree segmentTree;
    
public:
    MyCalendarTwo(): segmentTree(0, 1e9) {
        
    }
    
    bool book(int start, int end) {
        if(segmentTree.query(start, end - 1) >= 2){
            return false;
        }
        segmentTree.add(start, end - 1, 1);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
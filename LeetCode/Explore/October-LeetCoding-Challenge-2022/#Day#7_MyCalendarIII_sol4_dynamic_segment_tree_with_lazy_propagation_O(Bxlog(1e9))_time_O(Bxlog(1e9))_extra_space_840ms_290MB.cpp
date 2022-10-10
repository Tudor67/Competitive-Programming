class SegmentTree{
private:
    int l;
    int r;
    int val;
    int lazyVal;
    SegmentTree* leftChild;
    SegmentTree* rightChild;
    
    void updateAndLazyPropagate(SegmentTree* node){
        node->val += node->lazyVal;
        if(l != r){
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
        updateAndLazyPropagate(node);
        if(R < node->l || node->r < L){
            return;
        }else if(L <= node->l && node->r <= R){
            node->lazyVal += VAL;
            updateAndLazyPropagate(node);
        }else{
            int mid = (node->l + node->r) / 2;
            add(node->leftChild, L, R, VAL);
            add(node->rightChild, L, R, VAL);
            node->val = max(node->leftChild->val, node->rightChild->val);
        }
    }
    
public:
    SegmentTree(int l, int r, int val = 0, int lazyVal = 0, SegmentTree* leftChild = nullptr, SegmentTree* rightChild = nullptr):
                l(l), r(r), val(val), lazyVal(lazyVal), leftChild(leftChild), rightChild(rightChild){
        
    }
    /*
    ~SegmentTree(){
        delete leftChild;
        delete rightChild;
    }
    */
    void add(const int& L, const int& R, const int& VAL){
        add(this, L, R, VAL);
    }
    
    int getMax(){
        return this->val;
    }
};

class MyCalendarThree {
private:
    const int MIN_TIME = 0;
    const int MAX_TIME = 1e9 - 1;
    SegmentTree tree;
    
public:
    MyCalendarThree(): tree(MIN_TIME, MAX_TIME) {
        
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
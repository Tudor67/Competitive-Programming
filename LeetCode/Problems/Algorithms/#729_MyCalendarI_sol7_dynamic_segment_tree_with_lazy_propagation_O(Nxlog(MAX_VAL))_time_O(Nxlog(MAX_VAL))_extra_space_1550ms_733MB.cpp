class SegmentTree{
private:
    int l;
    int r;
    int val;
    int lazy;
    SegmentTree* leftChild;
    SegmentTree* rightChild;

    void propagate(SegmentTree* node){
        if(node == nullptr){
            return;
        }else if(node->l == node->r){
            node->val += node->lazy;
            node->lazy = 0;
        }else{
            if(node->leftChild == nullptr){
                node->leftChild = new SegmentTree(node->l, (node->l + node->r) / 2);
            }
            if(node->rightChild == nullptr){
                node->rightChild = new SegmentTree((node->l + node->r) / 2 + 1, node->r);
            }
            node->leftChild->lazy += node->lazy;
            node->rightChild->lazy += node->lazy;
            node->val += node->lazy * (node->r - node->l + 1);
            node->lazy = 0;
        }
    }

    void add(SegmentTree* node, const int L, const int R, const int VAL){
        propagate(node);
        if(node == nullptr || node->r < L || R < node->l){
            return;
        }
        if(L <= node->l && node->r <= R){
            node->lazy += VAL;
            propagate(node);
        }else{
            add(node->leftChild, L, R, VAL);
            add(node->rightChild, L, R, VAL);
            node->val = node->leftChild->val + node->rightChild->val;
        }
    }

    int computeSum(SegmentTree* node, const int L, const int R){
        propagate(node);
        if(node == nullptr || node->r < L || R < node->l){
            return 0;
        }
        if(L <= node->l && node->r <= R){
            return node->val;
        }
        return computeSum(node->leftChild, L, R) +
               computeSum(node->rightChild, L, R);
    }

public:
    SegmentTree(int l, int r): l(l), r(r){
        val = 0;
        lazy = 0;
        leftChild = nullptr;
        rightChild = nullptr;
    }

    ~SegmentTree(){
        delete leftChild;
        delete rightChild;
    }

    void add(const int L, const int R, const int VAL){
        add(this, L, R, VAL);
    }

    int computeSum(const int L, const int R){
        if(L > R){
            return 0;
        }
        return computeSum(this, L, R);
    }
};

class MyCalendar {
private:
    SegmentTree tree;

public:
    MyCalendar(): tree(0, 1e9 + 1) {

    }
    
    bool book(int start, int end) {
        if(tree.computeSum(start, end - 1) > 0){
            return false;
        }
        tree.add(start, end - 1, 1);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
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
            node->val += node->lazy;
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
            node->val = max(node->leftChild->val, node->rightChild->val);
        }
    }

    int computeMax(SegmentTree* node, const int L, const int R){
        propagate(node);
        if(node == nullptr || node->r < L || R < node->l){
            return 0;
        }
        if(L <= node->l && node->r <= R){
            return node->val;
        }
        return max(computeMax(node->leftChild, L, R),
                   computeMax(node->rightChild, L, R));
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

    int computeMax(const int L, const int R){
        if(L > R){
            return 0;
        }
        return computeMax(this, L, R);
    }
};

class MyCalendarTwo {
private:
    SegmentTree tree;

public:
    MyCalendarTwo(): tree(0, 1e9 + 1) {

    }
    
    bool book(int start, int end) {
        if(tree.computeMax(start, end - 1) >= 2){
            return false;
        }
        tree.add(start, end - 1, 1);
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
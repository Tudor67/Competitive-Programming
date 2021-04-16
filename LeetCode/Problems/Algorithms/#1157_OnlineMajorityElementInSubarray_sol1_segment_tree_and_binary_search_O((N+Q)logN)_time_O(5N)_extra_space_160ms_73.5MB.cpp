struct Node{
    int elem;
    int count;
    
    Node(int elem = 0, int count = 0){
        this->elem = elem;
        this->count = count;
    }
    
    friend ostream& operator<<(ostream& cout, const Node& NODE){
        cout << "{" << NODE.elem << ", " << NODE.count << "}";
        return cout;
    }
};

class SegmentTree{
private:
    const int N;
    vector<Node> tree;
    
    Node createWinnerNode(const Node& LEFT_NODE, const Node& RIGHT_NODE){
        Node node;
        if(LEFT_NODE.elem == RIGHT_NODE.elem){
            // Case 1: LEFT_NODE.elem == RIGHT_NODE.elem
            if(LEFT_NODE.elem == 0){
                node.elem = 0;
                node.count = 0;
            }else{
                node.elem = LEFT_NODE.elem;
                node.count = LEFT_NODE.count + RIGHT_NODE.count;
            }
        }else{
            // Case 2: LEFT_NODE.elem != RIGHT_NODE.elem
            if(LEFT_NODE.count == RIGHT_NODE.count){
                node.elem = 0;
            }else if(LEFT_NODE.count < RIGHT_NODE.count){
                node.elem = RIGHT_NODE.elem;
            }else if(LEFT_NODE.count > RIGHT_NODE.count){
                node.elem = LEFT_NODE.elem;
            }
            node.count = abs(LEFT_NODE.count - RIGHT_NODE.count);
        }
        return node;
    }
    
    void buildTree(int nodeIdx, int l, int r, vector<int>& arr){
        if(l == r){
            tree[nodeIdx].elem = arr[r];
            tree[nodeIdx].count = 1;
        }else{
            int mid = (l + r) / 2;
            int leftNodeIdx = 2 * nodeIdx + 1;
            int rightNodeIdx = 2 * nodeIdx + 2;
            buildTree(leftNodeIdx, l, mid, arr);
            buildTree(rightNodeIdx, mid + 1, r, arr);
            tree[nodeIdx] = createWinnerNode(tree[leftNodeIdx], tree[rightNodeIdx]);
        }
    }
    
    Node query(int nodeIdx, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return {0, 0};
        }
        if(L <= l && r <= R){
            return tree[nodeIdx];
        }
        int mid = (l + r) / 2;
        Node leftNode = query(2 * nodeIdx + 1, l, mid, L, R);
        Node rightNode = query(2 * nodeIdx + 2, mid + 1, r, L, R);
        return createWinnerNode(leftNode, rightNode);
    }
    
public:
    SegmentTree(vector<int>& arr): N(arr.size()){
        tree.resize(4 * N + 10);
        buildTree(0, 0, N - 1, arr);
    }
    
    Node query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class MajorityChecker {
private:
    SegmentTree segmentTree;
    map<int, vector<int>> positionsOf;
    
public:
    MajorityChecker(vector<int>& arr): segmentTree(arr) {
        for(int i = 0; i < (int)arr.size(); ++i){
            positionsOf[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int candidateElem = segmentTree.query(left, right).elem;
        vector<int>::iterator it1 = lower_bound(positionsOf[candidateElem].begin(), positionsOf[candidateElem].end(), left);
        vector<int>::iterator it2 = upper_bound(positionsOf[candidateElem].begin(), positionsOf[candidateElem].end(), right);
        int candidateElemCount = it2 - it1;
        if(candidateElemCount >= threshold){
            return candidateElem;
        }
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
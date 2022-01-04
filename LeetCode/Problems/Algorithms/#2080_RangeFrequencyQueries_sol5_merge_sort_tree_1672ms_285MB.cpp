class MergeSortTree{
private:
    const int N;
    vector<int> startIdx;
    vector<int> tree;
    
    void mergeSort(int i1, int len1, int i2, int len2, int i3){
        const int N1 = i1 + len1;
        const int N2 = i2 + len2;
        while(i1 < N1 && i2 < N2){
            if(tree[i1] <= tree[i2]){
                tree[i3] = tree[i1];
                i1 +=1;
            }else{
                tree[i3] = tree[i2];
                i2 += 1;
            }
            i3 += 1;
        }
        
        while(i1 < N1){
            tree[i3] = tree[i1];
            i1 += 1;
            i3 += 1;
        }
        
        while(i2 < N2){
            tree[i3] = tree[i2];
            i2 += 1;
            i3 += 1;
        }
    }
    
    void buildTree(int node, int l, int r, const vector<int>& V){
        if(l == r){
            tree[startIdx[node]] = V[l];
        }else{
            int mid = (l + r) / 2;
            int len1 = mid - l + 1;
            int len2 = r - mid;
            startIdx[2 * node + 1] = startIdx[node] + N;
            startIdx[2 * node + 2] = startIdx[node] + N + len1;
            buildTree(2 * node + 1, l, mid, V);
            buildTree(2 * node + 2, mid + 1, r, V);
            mergeSort(startIdx[2 * node + 1], len1, startIdx[2 * node + 2], len2, startIdx[node]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            int len = r - l + 1;
            if(tree[startIdx[node]] <= VAL && VAL <= tree[startIdx[node] + len - 1]){
                auto it1 = lower_bound(tree.begin() + startIdx[node], tree.begin() + startIdx[node] + len, VAL);
                auto it2 = upper_bound(it1, tree.begin() + startIdx[node] + len, VAL);
                return it2 - it1;
            }else{
                return 0;
            }
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R, VAL) +
               query(2 * node + 2, mid + 1, r, L, R, VAL);
    }
    
public:
    MergeSortTree(const vector<int>& V): N(V.size()){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        startIdx.resize(2 * minLeaves);
        tree.resize(minLeaves * (floor(log2(minLeaves)) + 1));
        buildTree(0, 0, N - 1, V);
    }
    
    int query(const int& L, const int& R, const int& VAL){
        return query(0, 0, N - 1, L, R, VAL);
    }
};

class RangeFreqQuery {
private:
    MergeSortTree tree;
    
public:
    RangeFreqQuery(vector<int>& arr): tree(arr){
        
    }
    
    int query(int left, int right, int value) {
        return tree.query(left, right, value);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
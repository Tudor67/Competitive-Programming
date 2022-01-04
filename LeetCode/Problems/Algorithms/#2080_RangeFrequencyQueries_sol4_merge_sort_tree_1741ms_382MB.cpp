class MergeSortTree{
private:
    const int N;
    vector<vector<int>> tree;
    
    void mergeSort(vector<int>& v1, vector<int>& v2, vector<int>& v3){
        const int N1 = v1.size();
        const int N2 = v2.size();
        
        v3.resize(N1 + N2);
        
        int i1 = 0;
        int i2 = 0;
        while(i1 < N1 && i2 < N2){
            if(v1[i1] <= v2[i2]){
                v3[i1 + i2] = v1[i1];
                i1 +=1;
            }else{
                v3[i1 + i2] = v2[i2];
                i2 += 1;
            }
        }
        
        while(i1 < N1){
            v3[i1 + i2] = v1[i1];
            i1 += 1;
        }
        
        while(i2 < N2){
            v3[i1 + i2] = v2[i2];
            i2 += 1;
        }
    }
    
    void buildTree(int node, int l, int r, const vector<int>& V){
        if(l == r){
            tree[node] = {V[l]};
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid, V);
            buildTree(2 * node + 2, mid + 1, r, V);
            mergeSort(tree[2 * node + 1], tree[2 * node + 2], tree[node]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            if(tree[node].front() <= VAL && VAL <= tree[node].back()){
                auto it1 = lower_bound(tree[node].begin(), tree[node].end(), VAL);
                auto it2 = upper_bound(it1, tree[node].end(), VAL);
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
        tree.resize(2 * minLeaves);
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
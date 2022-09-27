class SegmentTree{
private:
    const int N;
    vector<long long> tree;
    
    void update(int node, int l, int r, const int& POS, const long long& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    long long query(int node, int l, int r, const int& L, const int& R){
        if(R < l || r < L){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return query(2 * node + 1, l, mid, L, R) +
               query(2 * node + 2, mid + 1, r, L, R);
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const long long& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    long long query(const int& L, const int& R){
        if(L > R){
            return 0;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        const int N = nums.size();
        
        SegmentTree tree(N);
        for(int i = 0; i < N; ++i){
            tree.update(i, nums[i]);
        }
        
        set<tuple<long long, int, int>> slrSet;
        slrSet.emplace(tree.query(0, N - 1), 0, N - 1);
        set<int> qSet = {-1, N};
        
        vector<long long> res(N);
        for(int i = 0; i < N - 1; ++i){
            int mid = removeQueries[i];
            set<int>::iterator it = qSet.upper_bound(mid);
            int l = *prev(it) + 1;
            int r = *it - 1;
            
            slrSet.erase({tree.query(l, r), l, r});
            if(l <= mid - 1){
                slrSet.emplace(tree.query(l, mid - 1), l, mid - 1);
            }
            if(mid + 1 <= r){
                slrSet.emplace(tree.query(mid + 1, r), mid + 1, r);
            }
            
            qSet.insert(mid);
            tree.update(mid, 0);
            
            res[i] = get<0>(*prev(slrSet.end()));
        }
        
        return res;
    }
};
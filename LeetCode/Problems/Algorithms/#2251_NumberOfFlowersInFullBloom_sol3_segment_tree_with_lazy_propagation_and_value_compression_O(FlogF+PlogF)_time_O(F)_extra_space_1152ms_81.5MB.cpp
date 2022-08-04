class SegmentTree{
private:
    const int N;
    vector<int> tree;
    vector<int> lazy;
    
    void propagate(int node){
        tree[node] += lazy[node];
        if(2 * node + 2 < (int)lazy.size()){
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }
        lazy[node] = 0;
    }
    
    void add(int node, int l, int r, const int& L, const int& R, const int& VAL){
        propagate(node);
        if(r < L || R < l){
            // stop
        }else if(L <= l && r <= R){
            lazy[node] += VAL;
            propagate(node);
        }else{
            int mid = (l + r) / 2;
            add(2 * node + 1, l, mid, L, R, VAL);
            add(2 * node + 2, mid + 1, r, L, R, VAL);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        propagate(node);
        if(r < L || R < l){
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
        lazy.resize(2 * minLeaves);
    }
    
    void add(const int& L, const int& R, const int& VAL){
        add(0, 0, N - 1, L, R, VAL);
    }
    
    int query(const int& L, const int& R){
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        const int F = flowers.size();
        const int P = persons.size();
        
        // value compression for start/end times of flower blooms
        vector<int> b(2 * F);
        for(int i = 0; i < F; ++i){
            int startTime = flowers[i][0];
            int endTime = flowers[i][1] + 1;
            b[i] = startTime;
            b[i + F] = endTime;
        }
        
        sort(b.begin(), b.end());
        b.resize(unique(b.begin(), b.end()) - b.begin());
        
        // add all intervals of flower blooms
        // in a segment tree (with lazy propagation) using compressed times of flower blooms
        SegmentTree segmentTree(b.size());
        for(int i = 0; i < F; ++i){
            int startTime = flowers[i][0];
            int endTime = flowers[i][1] + 1;
            int compressedStartTime = lower_bound(b.begin(), b.end(), startTime) - b.begin();
            int compressedEndTime = lower_bound(b.begin(), b.end(), endTime) - b.begin();
            segmentTree.add(compressedStartTime, compressedEndTime - 1, 1);
        }
        
        // answer all the queries using the segment tree on the compressed values
        vector<int> answer(P);
        for(int j = 0; j < P; ++j){
            int compressedStartTime = lower_bound(b.begin(), b.end(), persons[j]) - b.begin();
            if(compressedStartTime < (int)b.size() && b[compressedStartTime] == persons[j]){
                answer[j] = segmentTree.query(compressedStartTime, compressedStartTime);
            }else if(compressedStartTime < (int)b.size() && compressedStartTime - 1 >= 0){
                answer[j] = segmentTree.query(compressedStartTime - 1, compressedStartTime - 1);
            }
        }
        
        return answer;
    }
};
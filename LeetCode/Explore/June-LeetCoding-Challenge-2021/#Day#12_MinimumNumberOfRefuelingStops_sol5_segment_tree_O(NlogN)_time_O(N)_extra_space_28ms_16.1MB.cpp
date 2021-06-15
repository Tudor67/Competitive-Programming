class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
    void set(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                set(2 * node + 1, l, mid, POS, VAL);
            }else{
                set(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void remove(int node, int l, int r, const int& L, const int& R, const int& VAL){
        if(l == r){
            tree[node] = 0;
        }else{
            int mid = (l + r) / 2;
            if(tree[2 * node + 1] == VAL){
                remove(2 * node + 1, l, mid, L, R, VAL);
            }else{
                remove(2 * node + 2, mid + 1, r, L, R, VAL);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return 0;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return max(query(2 * node + 1, l, mid, L, R),
                   query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& N): N(N){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, 0);
    }
    
    void set(const int& POS, const int& VAL){
        set(0, 0, N - 1, POS, VAL);
    }
    
    void remove(const int& L, const int& R, const int& VAL){
        if(L <= R){
            remove(0, 0, N - 1, L, R, VAL);
        }
    }
    
    int query(const int& L, const int& R){
        if(L <= R){
            return query(0, 0, N - 1, L, R);
        }
        return 0;
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int N = stations.size();
        const int SPECIAL_ELEMENT = -1;
        
        stations.push_back({target, SPECIAL_ELEMENT});
        
        SegmentTree segmentTree(N + 1);
        int gas = startFuel;
        int minStops = 0;
        for(int i = 0; i <= N; ++i){
            int dist = stations[i][0];
            while(gas < dist && segmentTree.query(0, i - 1) != 0){
                int stationGas = segmentTree.query(0, i - 1);
                gas += stationGas;
                segmentTree.remove(0, i - 1, stationGas);
                minStops += 1;
            }
            if(gas < dist){
                minStops = -1;
                break;
            }
            segmentTree.set(i, stations[i][1]);
        }
        
        return minStops;
    }
};
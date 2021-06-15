class SegmentTree{
private:
    const int N;
    const int SPECIAL_ELEMENT;
    const vector<int>& V;
    vector<int> tree;
    
    int getMaxChild(int leftChild, int rightChild){
        if(leftChild == SPECIAL_ELEMENT && rightChild == SPECIAL_ELEMENT){
            return SPECIAL_ELEMENT;
        }else if(leftChild == SPECIAL_ELEMENT){
            return rightChild;
        }else if(rightChild == SPECIAL_ELEMENT){
            return leftChild;
        }else{
            if(V[leftChild] >= V[rightChild]){
                return leftChild;
            }else{
                return rightChild;
            }
        }
    }
    
    void buildTree(int node, int l, int r){
        if(l == r){
            tree[node] = r;
        }else{
            int mid = (l + r) / 2;
            buildTree(2 * node + 1, l, mid);
            buildTree(2 * node + 2, mid + 1, r);
            tree[node] = getMaxChild(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    void update(int node, int l, int r, const int& POS, const int& VAL){
        if(l == r){
            tree[node] = VAL;
        }else{
            int mid = (l + r) / 2;
            if(POS <= mid){
                update(2 * node + 1, l, mid, POS, VAL);
            }else{
                update(2 * node + 2, mid + 1, r, POS, VAL);
            }
            tree[node] = getMaxChild(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    
    int query(int node, int l, int r, const int& L, const int& R){
        if(r < L || R < l){
            return SPECIAL_ELEMENT;
        }
        if(L <= l && r <= R){
            return tree[node];
        }
        int mid = (l + r) / 2;
        return getMaxChild(query(2 * node + 1, l, mid, L, R),
                           query(2 * node + 2, mid + 1, r, L, R));
    }
    
public:
    SegmentTree(const int& N, const vector<int>& V, const int& SPECIAL_ELEMENT): N(N), V(V), SPECIAL_ELEMENT(SPECIAL_ELEMENT){
        int minLeaves = 1;
        while(minLeaves < N){
            minLeaves *= 2;
        }
        tree.resize(2 * minLeaves, SPECIAL_ELEMENT);
        buildTree(0, 0, N - 1);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
    }
    
    int query(const int& L, const int& R){
        if(L > R){
            return SPECIAL_ELEMENT;
        }
        return query(0, 0, N - 1, L, R);
    }
};

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        const int N = stations.size();
        const int SPECIAL_ELEMENT = -1;
        
        stations.push_back({target, SPECIAL_ELEMENT});
        
        vector<int> stationsGas;
        for(const vector<int>& STATION: stations){
            stationsGas.push_back(STATION[1]);
        }
        SegmentTree segmentTree(N + 1, stationsGas, SPECIAL_ELEMENT);
        
        int gas = startFuel;
        int minStops = 0;
        for(int i = 0; i <= N; ++i){
            int dist = stations[i][0];
            while(gas < dist && segmentTree.query(0, i - 1) != SPECIAL_ELEMENT){
                int idx = segmentTree.query(0, i - 1);
                gas += stations[idx][1];
                segmentTree.update(idx, SPECIAL_ELEMENT);
                minStops += 1;
            }
            if(gas < dist){
                minStops = -1;
                break;
            }
        }
        
        return minStops;
    }
};
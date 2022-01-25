class SegmentTree{
private:
    const int N;
    vector<int> tree;
    
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
        tree.resize(2 * minLeaves);
    }
    
    void update(const int& POS, const int& VAL){
        update(0, 0, N - 1, POS, VAL);
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
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        const int N = obstacles.size();
        
        vector<int> sortedUniqueObstacles = obstacles;
        sort(sortedUniqueObstacles.begin(), sortedUniqueObstacles.end());
        sortedUniqueObstacles.resize(unique(sortedUniqueObstacles.begin(), sortedUniqueObstacles.end()) - sortedUniqueObstacles.begin());
        
        const int M = sortedUniqueObstacles.size();
        unordered_map<int, int> compressed;
        for(int i = 0; i < M; ++i){
            compressed[sortedUniqueObstacles[i]] = i;
        }
        
        SegmentTree segmentTree(M);
        vector<int> answer(N);
        for(int i = 0; i < N; ++i){
            answer[i] = 1 + segmentTree.query(0, compressed[obstacles[i]]);
            segmentTree.update(compressed[obstacles[i]], answer[i]);
        }
        
        return answer;
    }
};
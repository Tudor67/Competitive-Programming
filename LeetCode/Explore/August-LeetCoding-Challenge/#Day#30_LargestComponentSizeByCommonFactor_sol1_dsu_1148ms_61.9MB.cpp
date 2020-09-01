class DSU{
private:
    const int MAX_N;
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& MAX_N): MAX_N(MAX_N){
        rank.resize(MAX_N + 1);
        parent.resize(MAX_N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        
        if(rank[x_root] <= rank[y_root]){
            parent[x_root] = y_root;
        }else{
            parent[y_root] = x_root;
        }
        
        if(rank[x_root] == rank[y_root]){
            rank[y_root] += 1;
        }
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        const int MAX_N = *max_element(A.begin(), A.end());
        
        vector<bool> exists(MAX_N + 1, false);
        for(int i = 0; i < A.size(); ++i){
            exists[A[i]] = true;
        }
        
        DSU dsu(MAX_N);
        for(int i = 2; i <= MAX_N; ++i){
            for(int j = 2 * i; j <= MAX_N; j += i){
                if(exists[j]){
                    dsu.join(i, j);
                }
            }
        }
        
        vector<int> cnt(MAX_N + 1);
        for(int i = 0; i < A.size(); ++i){
            int root = dsu.find(A[i]);
            cnt[root] += 1;
        }
        
        int answer = *max_element(cnt.begin(), cnt.end());
        
        return answer;
    }
};
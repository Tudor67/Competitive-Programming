class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    DSU(const int& N){
        rank.resize(N + 1, 0);
        parent.resize(N + 1);
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x){
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    void join(int x, int y){
        int x_root = find(x);
        int y_root = find(y);
        if(x_root != y_root){
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
private:
    bool similar(const string& S1, const string& S2){
        int mismatch_cnt = 0;
        for(int i = 0; i < S1.length(); ++i){
            mismatch_cnt += (S1[i] != S2[i]);
            if(mismatch_cnt > 2){
                return false;
            }
        }
        return true;
    }
    
public:
    int numSimilarGroups(vector<string>& A) {
        const int N = A.size();
        
        DSU dsu(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(similar(A[i], A[j])){
                    dsu.join(i, j);
                }
            }
        }
        
        int connected_components = 0;
        for(int i = 0; i < N; ++i){
            connected_components += (i == dsu.find(i));
        }
        
        return connected_components;
    }
};
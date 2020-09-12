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
public:
    int findCircleNum(vector<vector<int>>& A) {
        const int N = A.size();
        
        DSU dsu(N);
        for(int node = 0; node < N; ++node){
            for(int next_node = node + 1; next_node < N; ++next_node){
                if(A[node][next_node]){
                    dsu.join(node, next_node);
                }
            }
        }
        
        int connected_components = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            int node_root = dsu.find(node);
            if(!vis[node_root]){
                connected_components += 1;
            }
            vis[node_root] = true;
        }
        
        return connected_components;
    }
};
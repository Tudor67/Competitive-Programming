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
    int get_redundant_edges_and_update_dsu(const vector<vector<int>>& EDGES, const int& EDGE_TYPE, DSU& dsu){
        int redundant_edges = 0;
        for(const vector<int>& EDGE: EDGES){
            int edge_type = EDGE[0];
            int x = EDGE[1];
            int y = EDGE[2];
            if(edge_type == EDGE_TYPE){
                if(dsu.find(x) == dsu.find(y)){
                    redundant_edges += 1;
                }else{
                    dsu.join(x, y);
                }
            }
        }
        return redundant_edges;
    }
    
    bool is_a_connected_graph(DSU& dsu, const int& N){
        const int UNIQUE_ROOT = dsu.find(1);
        for(int node = 2; node <= N; ++node){
            if(dsu.find(node) != UNIQUE_ROOT){
                return false;
            }
        }
        return true;
    }

public:
    int maxNumEdgesToRemove(int N, vector<vector<int>>& edges) {
        int redundant_edges = 0;
        
        DSU dsu3(N);
        redundant_edges += get_redundant_edges_and_update_dsu(edges, 3, dsu3);

        DSU dsu1 = dsu3;
        redundant_edges += get_redundant_edges_and_update_dsu(edges, 1, dsu1);
        
        DSU dsu2 = dsu3;
        redundant_edges += get_redundant_edges_and_update_dsu(edges, 2, dsu2);
        
        int answer = redundant_edges;
        if(!is_a_connected_graph(dsu1, N) || !is_a_connected_graph(dsu2, N)){
            answer = -1;
        }
        
        return answer;
    }
};
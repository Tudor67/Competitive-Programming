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
            // union
            if(rank[x_root] <= rank[y_root]){
                parent[x_root] = y_root;
            }else{
                parent[y_root] = x_root;
            }
            // update rank
            if(rank[x_root] == rank[y_root]){
                rank[y_root] += 1;
            }
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> answer;
        DSU dsu(edges.size());
        for(const vector<int>& EDGE: edges){
            int x_root = dsu.find(EDGE[0]);
            int y_root = dsu.find(EDGE[1]);
            if(x_root == y_root){
                answer = EDGE;
                break;
            }else{
                dsu.join(EDGE[0], EDGE[1]);
            }
        }
        return answer;
    }
};
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
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& arcs) {
        const int N = arcs.size();
        vector<int> in_degree(N + 1, 0);
        for(const vector<int>& ARC: arcs){
            in_degree[ARC[1]] += 1;
        }
        
        // spercial_arcs which contain the node with in_degree == 2 (if it exists)
        // we can have maximum 2 special arcs
        // these arcs will be added later to dsu
        vector<vector<int>> special_arcs;
        DSU dsu(N);
        vector<int> answer;
        for(const vector<int>& ARC: arcs){
            if(in_degree[ARC[1]] == 2){
                special_arcs.push_back(ARC);
            }else{
                if(dsu.find(ARC[0]) == dsu.find(ARC[1])){
                    answer = ARC;
                    break;
                }
                dsu.join(ARC[0], ARC[1]);
            }
        }
        
        for(const vector<int>& ARC: special_arcs){
            if(dsu.find(ARC[0]) == dsu.find(ARC[1])){
                answer = ARC;
            }else{
                dsu.join(ARC[0], ARC[1]);
            }
        }
        
        return answer;
    }
};
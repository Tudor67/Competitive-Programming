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
    int removeStones(vector<vector<int>>& stones) {
        const int MAX_VAL = 1e4;
        const int N = stones.size();
        
        DSU dsu(2 * MAX_VAL);
        for(const vector<int>& STONE: stones){
            int x = STONE[0];
            int y = STONE[1];
            dsu.join(x, y + MAX_VAL);
        }
        
        vector<int> connected_component_size(2 * MAX_VAL + 1, 0);
        for(const vector<int>& STONE: stones){
            int x = STONE[0];
            int x_root = dsu.find(x);
            connected_component_size[x_root] += 1;
        }
        
        int answer = 0;
        for(int node_root = 0; node_root <= 2 * MAX_VAL; ++node_root){
            if(connected_component_size[node_root] >= 2){
                answer += (connected_component_size[node_root] - 1);
            }
        }
        
        return answer;
    }
};
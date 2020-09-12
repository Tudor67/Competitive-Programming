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
    static bool x_asc_comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] < RHS[0]);
    }
    
    static bool y_asc_comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();
        DSU dsu(N);
        
        vector<vector<int>> stones3(N);
        for(int i = 0; i < N; ++i){
            stones3[i] = {stones[i][0], stones[i][1], i};
        }
        
        sort(stones3.begin(), stones3.end(), x_asc_comp);
        for(int i = 1; i < N; ++i){
            if(stones3[i - 1][0] == stones3[i][0]){
                int idx1 = stones3[i - 1][2];
                int idx2 = stones3[i][2];
                dsu.join(idx1, idx2);
            }
        }
        
        sort(stones3.begin(), stones3.end(), y_asc_comp);
        for(int i = 1; i < N; ++i){
            if(stones3[i - 1][1] == stones3[i][1]){
                int idx1 = stones3[i - 1][2];
                int idx2 = stones3[i][2];
                dsu.join(idx1, idx2);
            }
        }
        
        vector<int> connected_component_size(N, 0);
        for(int node = 0; node < N; ++node){
            int node_root = dsu.find(node);
            connected_component_size[node_root] += 1;
        }
        
        int answer = 0;
        for(int node_root = 0; node_root < N; ++node_root){
            if(connected_component_size[node_root] >= 2){
                answer += (connected_component_size[node_root] - 1);
            }
        }
        
        return answer;
    }
};
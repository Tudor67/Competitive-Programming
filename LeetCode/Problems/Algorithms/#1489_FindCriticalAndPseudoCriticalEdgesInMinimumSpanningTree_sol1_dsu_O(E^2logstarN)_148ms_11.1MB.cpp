class DSU{
private:
    vector<int> parent;
    vector<int> rank;
    
public:
    void init(const int& N){
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
    DSU dsu;
    
    int minimum_spanning_tree_weight(const int& N, const vector<vector<int>>& SORTED_EDGES, int special_edge = -1, bool use_special_edge = false){
        int weight = 0;
        dsu.init(N);
        
        if(use_special_edge){
            for(int i = 0; i < SORTED_EDGES.size(); ++i){
                if(SORTED_EDGES[i][3] == special_edge){
                    dsu.join(SORTED_EDGES[i][0], SORTED_EDGES[i][1]);
                    weight += SORTED_EDGES[i][2];
                    break;
                }
            }
        }
        
        for(int i = 0; i < SORTED_EDGES.size(); ++i){
            if(SORTED_EDGES[i][3] == special_edge){
                continue;
            }
            if(dsu.find(SORTED_EDGES[i][0]) != dsu.find(SORTED_EDGES[i][1])){
                dsu.join(SORTED_EDGES[i][0], SORTED_EDGES[i][1]);
                weight += SORTED_EDGES[i][2];
            }
        }
        
        return weight;
    }
    
    static bool comp_by_weight(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[2] < RHS[2]);
    }
    
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int N, vector<vector<int>>& edges) {
        vector<vector<int>> sorted_edges(edges.size(), vector<int>(4));
        for(int i = 0; i < sorted_edges.size(); ++i){
            copy(edges[i].begin(), edges[i].end(), sorted_edges[i].begin());
            sorted_edges[i][3] = i;
        }
        
        sort(sorted_edges.begin(), sorted_edges.end(), comp_by_weight);
        
        vector<vector<int>> answer(2);
        const int EXPECTED_MST_WEIGHT = minimum_spanning_tree_weight(N, sorted_edges);
        for(int special_edge = 0; special_edge < sorted_edges.size(); ++special_edge){
            if(EXPECTED_MST_WEIGHT != minimum_spanning_tree_weight(N, sorted_edges, special_edge, false)){
                answer[0].push_back(special_edge);
            }else if(EXPECTED_MST_WEIGHT == minimum_spanning_tree_weight(N, sorted_edges, special_edge, true)){
                answer[1].push_back(special_edge);
            }
        }

        return answer;
    }
};
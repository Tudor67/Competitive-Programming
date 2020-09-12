class Solution {
private:
    void bfs(const int& SRC_NODE, const vector<vector<int>>& G, vector<bool>& vis, int& connected_component_size){
        connected_component_size = 0;
        queue<int> q;
        q.push(SRC_NODE);
        vis[SRC_NODE] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            connected_component_size += 1;
            for(int next_node: G[node]){
                if(!vis[next_node]){
                    q.push(next_node);
                    vis[next_node] = true;
                }
            }
        }
    }
    
    static bool x_asc_comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] < RHS[0]);
    }
    
    static bool y_asc_comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[1] < RHS[1]);
    }
    
public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();
        vector<vector<int>> G(N);
        
        vector<vector<int>> stones3(N);
        for(int i = 0; i < N; ++i){
            stones3[i] = {stones[i][0], stones[i][1], i};
        }
        
        sort(stones3.begin(), stones3.end(), x_asc_comp);
        for(int i = 1; i < N; ++i){
            if(stones3[i - 1][0] == stones3[i][0]){
                int idx1 = stones3[i - 1][2];
                int idx2 = stones3[i][2];
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
        
        sort(stones3.begin(), stones3.end(), y_asc_comp);
        for(int i = 1; i < N; ++i){
            if(stones3[i - 1][1] == stones3[i][1]){
                int idx1 = stones3[i - 1][2];
                int idx2 = stones3[i][2];
                G[idx1].push_back(idx2);
                G[idx2].push_back(idx1);
            }
        }
        
        int answer = 0;
        vector<bool> vis(N, false);
        for(int node = 0; node < N; ++node){
            if(!vis[node]){
                int connected_component_size = 0;
                bfs(node, G, vis, connected_component_size);
                answer += (connected_component_size - 1);
            }
        }
        
        return answer;
    }
};
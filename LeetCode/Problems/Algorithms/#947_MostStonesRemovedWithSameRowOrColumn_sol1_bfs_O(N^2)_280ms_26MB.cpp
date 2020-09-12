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
    
public:
    int removeStones(vector<vector<int>>& stones) {
        const int N = stones.size();
        vector<vector<int>> G(N);
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                    G[i].push_back(j);
                    G[j].push_back(i);
                }
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
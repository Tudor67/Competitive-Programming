class Solution {
private:
    vector<int> dist;
    queue<int> q;
    
    void bfs(const int& SRC, const int& NODES_MASK, vector<vector<int>>& neighbors, vector<int>& dist){
        dist.resize(neighbors.size());
        fill(dist.begin(), dist.end(), -1);
        dist[SRC] = 0;
        q.push(SRC);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nextNode: neighbors[node]){
                if(((NODES_MASK >> nextNode) & 1) && dist[nextNode] == -1){
                    q.push(nextNode);
                    dist[nextNode] = 1 + dist[node];
                }
            }
        }
    }
    
    int getMaxDist(const int& NODES_MASK, vector<vector<int>>& neighbors){
        int src = __builtin_ctz(NODES_MASK);
        bfs(src, NODES_MASK, neighbors, dist);
        src = max_element(dist.begin(), dist.end()) - dist.begin();
        bfs(src, NODES_MASK, neighbors, dist);
        
        int maxDist = *max_element(dist.begin(), dist.end());
        for(int node = 0; node < neighbors.size(); ++node){
            if(((NODES_MASK >> node) & 1) && dist[node] == -1){
                maxDist = -1;
                break;
            }
        }
        
        return maxDist;
    }
    
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> neighbors(n);
        for(const vector<int>& EDGE: edges){
            neighbors[EDGE[0] - 1].push_back(EDGE[1] - 1);
            neighbors[EDGE[1] - 1].push_back(EDGE[0] - 1);
        }
        
        vector<int> answer(n - 1);
        const int FULL_MASK = (1 << n) - 1;
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            int maxDist = getMaxDist(mask, neighbors);
            if(maxDist - 1 >= 0){
                answer[maxDist - 1] += 1;
            }
        }
        
        return answer;
    }
};
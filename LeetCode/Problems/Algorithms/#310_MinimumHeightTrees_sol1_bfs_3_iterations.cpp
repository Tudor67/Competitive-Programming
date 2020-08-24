class Solution {
private:
    void bfs(const int& src, const vector<vector<int>>& neighbors, vector<int>& dist){
        queue<int> q;
        q.push(src);
        
        fill(dist.begin(), dist.end(), -1);
        dist[src] = 0;
        
        while(!q.empty()){
            int x = q.front();
            q.pop();
            
            for(int y: neighbors[x]){
                if(dist[y] == -1){
                    q.push(y);
                    dist[y] = 1 + dist[x];
                }
            }
        }
    }
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        // create the graph
        vector<vector<int>> neighbors(n);
        for(const vector<int>& edge: edges){
            neighbors[edge[0]].push_back(edge[1]);
            neighbors[edge[1]].push_back(edge[0]);
        }
        
        // bfs from 0
        int src = 0;
        vector<int> dist(n);
        bfs(src, neighbors, dist);
        
        // bfs from leaf1
        int src1 = max_element(dist.begin(), dist.end()) - dist.begin();
        vector<int> dist1(n);
        bfs(src1, neighbors, dist1);
        
        // bfs from leaf2
        int src2 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<int> dist2(n);
        bfs(src2, neighbors, dist2);
        
        // compute diameter
        int diameter = *max_element(dist2.begin(), dist2.end());
        
        // save nodes from the middle of the graph
        vector<int> answer;
        for(int node = 0; node < n; ++node){
            if(min(dist1[node], dist2[node]) == diameter / 2 &&
               dist1[node] + dist2[node] == diameter){
                answer.push_back(node);
            }
        }
        
        return answer;
    }
};
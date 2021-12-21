class Solution {
private:
    void bfs(int srcNode, vector<vector<int>>& g, vector<int>& dist){
        static const int INF = 1e8;
        
        fill(dist.begin(), dist.end(), INF);
        
        queue<int> q;
        q.push(srcNode);
        dist[srcNode] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: g[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
    }
    
public:
    vector<int> findMinHeightTrees(int N, vector<vector<int>>& edges) {
        vector<vector<int>> g(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vector<int> dist(N);
        bfs(0, g, dist);
        
        int srcNode1 = max_element(dist.begin(), dist.end()) - dist.begin();
        vector<int> dist1(N);
        bfs(srcNode1, g, dist1);
        
        int srcNode2 = max_element(dist1.begin(), dist1.end()) - dist1.begin();
        vector<int> dist2(N);
        bfs(srcNode2, g, dist2);
        
        int diameter = *max_element(dist1.begin(), dist1.end());
        
        vector<int> answer;
        for(int node = 0; node < N; ++node){
            if(min(dist1[node], dist2[node]) == diameter / 2 && dist1[node] + dist2[node] == diameter){
                answer.push_back(node);
            }
        }
        
        return answer;
    }
};
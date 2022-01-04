class Solution {
private:
    void bfs(int srcNode, const vector<vector<int>>& G, vector<int>& dist){
        const int N = G.size();
        const int INF = 1e8;
        
        dist.assign(N, INF);
        queue<int> q;
        q.push(srcNode);
        dist[srcNode] = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: G[node]){
                if(dist[node] + 1 < dist[nextNode]){
                    dist[nextNode] = dist[node] + 1;
                    q.push(nextNode);
                }
            }
        }
    }
    
    int computeTotalTime(int edges, int time, int change){
        int totalTime = 0;
        while(edges > 0){
            edges -= 1;
            totalTime += time;
            if((totalTime / change) % 2 == 1){
                if(edges > 0){
                    totalTime = (totalTime / change + 1) * change;
                }
            }
        }
        return totalTime;
    }
    
public:
    int secondMinimum(int N, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> g(N);
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0] - 1;
            int y = EDGE[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        
        vector<int> distFromFirst;
        bfs(0, g, distFromFirst);
        
        vector<int> distFromLast;
        bfs(N - 1, g, distFromLast);
        
        const int MIN_PATH_SIZE = distFromFirst[N - 1];
        
        // check if there is a path of length (MIN_PATH_SIZE + 1) edges
        bool nextPathExists = false;
        for(int node = 1; !nextPathExists && node < N; ++node){
            if(distFromFirst[node] + distFromLast[node] == MIN_PATH_SIZE){
                // node is on the min path
                for(int nextNode: g[node]){
                    if(distFromFirst[node] == distFromFirst[nextNode]){
                        nextPathExists = true;
                    }
                }
            }
        }
        
        int secondMinTime = 0;
        if(nextPathExists){
            secondMinTime = computeTotalTime(MIN_PATH_SIZE + 1, time, change);
        }else{
            secondMinTime = computeTotalTime(MIN_PATH_SIZE + 2, time, change);
        }
        
        return secondMinTime;
    }
};
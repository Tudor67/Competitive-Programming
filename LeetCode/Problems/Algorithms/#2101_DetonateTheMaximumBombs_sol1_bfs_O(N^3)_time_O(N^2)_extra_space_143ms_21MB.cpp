class Solution {
private:
    bool canDetonate(const vector<int>& SRC, const vector<int>& DEST){
        long long srcX = SRC[0];
        long long srcY = SRC[1];
        long long srcR = SRC[2];
        long long destX = DEST[0];
        long long destY = DEST[1];
        long long dx = srcX - destX;
        long long dy = srcY - destY;
        return (dx * dx + dy * dy <= srcR * srcR);
    }
    
    int bfs(int srcNode, vector<vector<int>>& g, vector<bool>& vis){
        fill(vis.begin(), vis.end(), false);
        
        queue<int> q;
        q.push(srcNode);
        vis[srcNode] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int nextNode: g[node]){
                if(!vis[nextNode]){
                    vis[nextNode] = true;
                    q.push(nextNode);
                }
            }
        }
        
        return count(vis.begin(), vis.end(), true);
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        const int N = bombs.size();
        
        vector<vector<int>> g(N);
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && canDetonate(bombs[i], bombs[j])){
                    g[i].push_back(j);
                }
            }
        }
        
        int answer = 0;
        vector<bool> vis(N);
        for(int i = 0; i < N; ++i){
            int detonations = bfs(i, g, vis);
            answer = max(answer, detonations);
        }
        
        return answer;
    }
};
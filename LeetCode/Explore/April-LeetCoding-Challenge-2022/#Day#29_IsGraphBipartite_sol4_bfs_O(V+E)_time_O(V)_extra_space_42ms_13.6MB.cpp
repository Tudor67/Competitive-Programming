class Solution {
private:
    void bfs(int startNode, vector<int>& colorOf, vector<vector<int>>& graph, bool& isBipartite){
        queue<int> q;
        q.push(startNode);
        colorOf[startNode] = 0;
        
        while(!q.empty() && isBipartite){
            int node = q.front();
            q.pop();
            
            for(int nextNode: graph[node]){
                if(colorOf[nextNode] == -1){
                    colorOf[nextNode] = (colorOf[node] + 1) % 2;
                    q.push(nextNode);
                }else if(colorOf[nextNode] == colorOf[node]){
                    isBipartite = false;
                }
            }
        }
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int N = graph.size();
        
        vector<int> colorOf(N, -1);
        bool isBipartite = true;
        for(int node = 0; node < N && isBipartite; ++node){
            if(colorOf[node] == -1){
                bfs(node, colorOf, graph, isBipartite);
            }
        }
        
        return isBipartite;
    }
};
class Solution {
private:
    void dfs(int node, vector<bool>& vis, vector<bool>& isInStack, vector<vector<int>>& g,
             vector<int>& topSortNodes, bool& cycleFound){
        vis[node] = true;
        isInStack[node] = true;
        for(int nextNode: g[node]){
            if(isInStack[nextNode]){
                cycleFound = true;
            }else if(!vis[nextNode] && !cycleFound){
                dfs(nextNode, vis, isInStack, g, topSortNodes, cycleFound);
            }
        }
        isInStack[node] = false;
        topSortNodes.push_back(node);
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        const int N = numCourses;
        vector<vector<int>> g(N);
        for(const vector<int>& P: prerequisites){
            g[P[1]].push_back(P[0]);
        }
        
        bool cycleFound = false;
        vector<bool> vis(N, false);
        vector<bool> isInStack(N, false);
        vector<int> topSortNodes;
        for(int node = 0; node < N; ++node){
            if(!vis[node] && !cycleFound){
                dfs(node, vis, isInStack, g, topSortNodes, cycleFound);
            }
        }
        
        reverse(topSortNodes.begin(), topSortNodes.end());
        
        if(cycleFound){
            topSortNodes.clear();
        }
        
        return topSortNodes;
    }
};